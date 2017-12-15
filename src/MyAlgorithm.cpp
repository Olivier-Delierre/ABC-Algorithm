#include <iomanip>
#include "../include/MyAlgorithm.h"


MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup) : _solutions{}, _trial{}, _fitness_values{}, _setup{ setup }
{
	_solutions.resize(_setup.population_size());
	_fitness_values.resize(_setup.population_size());
	for (int i = 0; i<_setup.population_size(); ++i)
	{
		_solutions[i] = new Solution{ pbm };
		_fitness_values[i] = _solutions[i]->fitness();
	};
}

void MyAlgorithm::initialize()
{
	for (int i = 0; i<_solutions.size(); ++i)
	{
		_solutions[i]->initialize();
		_fitness_values[i] = _solutions[i]->fitness();
	}
}


/**
 * Function which send the employed bees of the Algorithm. It consist of generating for each
 * solutions of the Algorithm, a random parameter which represents a dimension number.
 *
 * This algorithm calculate a new value for this precise food.
 */ 
void MyAlgorithm::sendEmployedBees()
{
	for (unsigned int i = 0; i < _setup.population_size(); i++)
	{
		// Calculation of a random parameter between 0 and the dimension size -1
		int randomParameter = rand()%_setup.population_size();
		// Calculation of a random food between 0 and the size of the solution -1
		int randomFood = rand()%_setup.solution_size();

		double newValue = 
				_solutions[i]->solution()[randomParameter] 
				+ (rand()%1) 
				* (_solutions[i]->solution()[randomParameter] - _solutions[randomFood]->solution()[randomParameter]);
	
		// If we get a better solution than previous, we set it, and the number of trial return to 0
		if (newValue > _solutions[i]->solution()[randomParameter]) 
		{
			_solutions[i]->solution()[randomParameter]; 
			_trial[i] = 0;
		}
		// Else, we incremente the number of trial
		else
		{
			_trial[i]++;
		}
	}
}

double MyAlgorithm::evolution()
{
	for (unsigned int i = 0; i < _setup.independent_runs(); i++)
	{
		initialize();
		for (unsigned int j = 0; j < _setup.nb_evolution_steps(); j++)
		{
			sendEmployedBees();
			sendOnLookerBees();
			sendScoutBees();
			cout << "Run " << setw(3) << i + 1 << " evolution " << setw(6) << j + 1 << " : " << setw(10) << best_cost() << std::endl;
		}
	}
	return 0;
}

void MyAlgorithm::evaluate()
{
	for (unsigned int i = 0; i < _solutions.size(); i++)
		_fitness_values[i] = _solutions[i]->fitness();
}

/**
Destructor of MyAlgorithm

*/
MyAlgorithm::~MyAlgorithm()
{
	for (unsigned int i = 0; i < _solutions.size(); i++)
	{
		delete _solutions[i];
	}
}

/**
Return the individuals in population

@return _solutions - returns the individuals in population
*/
const vector<Solution*>& MyAlgorithm::solutions() const
{
	return _solutions;
}

/**
	Return the fitness number index
*/
double MyAlgorithm::fitness(const int index) const
{ 
	return _fitness_values[index];
}


/*
	Return best fitness' index
*/
int MyAlgorithm::upper_cost() const
{
	double max = 0;
	for (int i = 1; i < _setup.population_size(); i++) if (_fitness_values[i] > _fitness_values[max]) max = i;
	return max;
}

/*
Return lower fitness' index
*/
int MyAlgorithm::lower_cost() const
{
	double min = 0;
	for (int i = 1; i < _setup.population_size(); i++) if (_fitness_values[i] < _fitness_values[min]) min = i;
	return min;
}

/*
	Return best fitness
*/
double MyAlgorithm::best_cost()  const
{
	return fitness(lower_cost()); 
}


/*
	Return worst fitness
 */
double MyAlgorithm::worst_cost() const 
{
	return fitness(upper_cost()); 
}

/**
Return the individual index in population

@return _solutions[index] - returns the individual index in population
*/
Solution& MyAlgorithm::solution(const unsigned int index) const
{
	return *(_solutions[index]);
}

/**
Return the fitness 

@return _fitness_values[index] - returns the fitness
*/
double MyAlgorithm::fitness(const unsigned int index) const
{
	return _fitness_values[index];
}


