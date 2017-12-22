#include "MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& problem, const SetUpParams& params) : 
	_params{ params },
	_solutions{}, 
	_fitness_values{}, 
	_probabilities{},
	_trials{}
{
	_solutions.resize(_params.population_size());
	_fitness_values.resize(_params.population_size());
	_probabilities.resize(_params.population_size());
	_trials.resize(_params.population_size());
	for (unsigned int i = 0; i < _params.population_size(); i++)
	{
		_solutions[i] = new Solution{ problem };
	}
}

void MyAlgorithm::initialize()
{
	for (unsigned int i = 0; i<_solutions.size(); i++)
	{
		_solutions[i]->initialize();
		_solutions[i]->calculate_fitness();
	}
}

void MyAlgorithm::evaluate()
{
	for (unsigned int i = 0; i < _solutions.size(); i++)
	{
        _solutions[i]->calculate_fitness();
		_fitness_values[i] = _solutions[i]->current_fitness();
	}
}

void MyAlgorithm::evolution()
{
	for (unsigned int i = 0; i < _params.nb_evolution_steps(); i++)
	{
		initialize();
		for (unsigned int j = 0; j < _params.independent_runs() / _params.nb_evolution_steps(); j++)
		{   
            std::cin.ignore(1024, '\n');
            std::cout << "Press enter to continue ...";
            std::cin.get();

            system("clear");
            evaluate();
			std::cout << "Run " << std::setw(3) << i + 1 << " evolution " << std::setw(6) << j + 1 << " : " << std::setw(10) << best_cost() << std::endl;
			send_employed_bees();
			//send_onlooker_bees();
			send_scout_bees();

            ///Debug usage
            std::cout << "Fitness values :" << std::endl;
            for (int k = 0; k < _fitness_values.size(); k++) std::cout << k << ':' << _fitness_values[k] << std::endl;
		}
	}
}


MyAlgorithm::~MyAlgorithm()
{
	for (unsigned int i = 0; i < _solutions.size(); i++)
	{
		delete _solutions[i];
	}
}

std::vector<Solution*> MyAlgorithm::solutions() const
{ return _solutions; }

std::vector<double> MyAlgorithm::fitness_values() const
{ return _fitness_values; }

double MyAlgorithm::upper_cost() const
{
	double max = 0;

	for (unsigned int i = 1; i < _params.population_size(); i++) 
	{
		if (_fitness_values[i] > _fitness_values[max]) max = i;
	}

	return max;
}

double MyAlgorithm::lower_cost() const
{
	double min = 0;
	
	for (unsigned int i = 1; i < _params.population_size(); i++) 
	{
		if (_fitness_values[i] < _fitness_values[min]) min = i;
	}

	return min;
}

double MyAlgorithm::best_cost()  const
{
	return _fitness_values[lower_cost()]; 
}

double MyAlgorithm::worst_cost() const 
{
	return _fitness_values[upper_cost()]; 
}

void MyAlgorithm::send_bees()
{
}

void MyAlgorithm::send_employed_bees()
{
	for (unsigned int i = 0; i < _params.population_size(); i++)
	{
		// Calculation of a random parameter between 0 and the dimension size -1
		int randomParameter = rand()%_params.population_size();
		// Calculation of a random food between 0 and the size of the solution -1
		int randomFood = rand()%_params.solution_size();

		double newValue = 
				_solutions[i]->solution()[randomParameter] 
				+ (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) 
				* (_solutions[i]->solution()[randomParameter] - _solutions[randomFood]->solution()[randomParameter]);
	
		if (newValue > _solutions[i]->solution()[randomParameter]) 
		{
			_solutions[i]->solution()[randomParameter]; 
			_trials[i] = 0;
		}
		else
		{
			_trials[i]++;
		}
	}
}

void MyAlgorithm::send_onlooker_bees()
{
	calculate_probabilities();

	int t = 0;
	int i = 0;

	while (t < _params.population_size())
	{
		int r = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX));
		if (r < _probabilities[i])
		{
			t++;
			/*parameter to be changed is determined randomly between 0 and the dimension size -1*/
			int param2change = rand() % _params.population_size();
			/*A randomly chosen solution is used in producing a mutant solution of the solution i*/
			int neighbour = rand() % _params.solution_size();
			/*Randomly selected solution must be different from the solution i*/
			double newValue =
				_solutions[i]->solution()[param2change]
				+ (static_cast<double>(rand()) / static_cast<double>(RAND_MAX))
				* (_solutions[i]->solution()[param2change] - _solutions[neighbour]->solution()[param2change]);

			if (newValue > _solutions[i]->solution()[param2change])
			{
				_solutions[i]->solution()[param2change];
				_trials[i] = 0;
			}
			else
			{
				_trials[i]++;
			}
		}
		i++;
		if (i == _params.population_size())
			i = 0;
	}
}

void MyAlgorithm::send_scout_bees()
{
	unsigned int max_trial_index{ 0 };
	for (unsigned int i = 0; i < _params.population_size(); i++)
	{
		if (_trials[i] > _trials[max_trial_index])
		{
			max_trial_index = i;
		}
	}

	if (_trials[max_trial_index] > _params.max_trials())
	{
		_solutions[max_trial_index]->initialize();
	}
}

void MyAlgorithm::calculate_probabilities()
{
	double sumfit = 0;
 
	for (unsigned int i = 0; i < _params.solution_size(); i++)
	{
			sumfit += _fitness_values[i];
	}

	for (unsigned int i = 0; i < _params.solution_size(); i++)
	{
		_probabilities[i] = _fitness_values[i] / sumfit;
	}
}
