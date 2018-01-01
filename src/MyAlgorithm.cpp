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

MyAlgorithm::~MyAlgorithm()
{
	for (unsigned int i = 0; i < _solutions.size(); i++)
	{
		delete _solutions[i];
	}
}

void MyAlgorithm::initialize()
{
	for (unsigned int i = 0; i < _solutions.size(); i++)
	{
		_solutions[i]->initialize();
		evaluate();
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
            system("CLS");
            evaluate();
			std::cout << "Run " << std::setw(3) << i + 1 << " evolution " << std::setw(6) << j + 1 << " : " << std::setw(10) << best_cost() << std::endl;
			send_employed_bees();
			send_onlooker_bees();
			system("pause");
			send_scout_bees();
        }
	}
}

std::vector<Solution*> MyAlgorithm::solutions() const
{ return _solutions; }

std::vector<double> MyAlgorithm::fitness_values() const
{ return _fitness_values; }

int MyAlgorithm::upper_cost() const
{
	int max = 0;

	for (unsigned int i = 1; i < _params.population_size(); i++) 
	{
		if (_fitness_values[i] > _fitness_values[max]) max = i;
	}

	return max;
}

int MyAlgorithm::lower_cost() const
{
	int min = 0;
	
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

void MyAlgorithm::send_bees(int parameter_to_change, int i)
{
    int neighbour{ -1 };
    
    do {
        neighbour = rand() % _params.solution_size();
    } while (neighbour == i);

    double new_value{ 
            _solutions[i]->solution()[parameter_to_change] 
            + (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) 
            * (_solutions[i]->solution()[neighbour] - _solutions[neighbour]->solution()[parameter_to_change])
            };

    Solution *new_solution = new Solution(*_solutions[i]);
    new_solution->set_value_to_index(new_value, parameter_to_change);
    double new_fitness = new_solution->return_fitness(); 

    if (new_fitness < _solutions[i]->current_fitness()) 
    {
        _solutions[i]->set_value_to_index(new_value, parameter_to_change); 
        _trials[i] = 0;
    }

    else
    {
        _trials[i]++;
    }

    delete new_solution;
}

void MyAlgorithm::send_employed_bees()
{
    for (unsigned int i = 0; i < _params.population_size(); i++)
    {
        int parameter_to_change = rand() % _params.population_size();
        send_bees(parameter_to_change, i);
    }
}

void MyAlgorithm::send_onlooker_bees()
{
	calculate_probabilities();
    for (unsigned int i = 0; i < _params.population_size(); i++)
    {
		int parameter_to_change = _probabilities[i];
		send_bees(parameter_to_change, i);

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
	double sumfit{ 0 };
 
	for (unsigned int i = 0; i < _params.population_size(); i++)
	{
			sumfit += _solutions[i]->real_current_fitness();
	}

	for (unsigned int i = 0; i < _params.population_size(); i++)
	{
		_probabilities[i] = _solutions[i]->real_current_fitness() / sumfit * 100;
	}
	//sort_probabilities(_probabilities);
}


void MyAlgorithm::sort_probabilities()
{

}