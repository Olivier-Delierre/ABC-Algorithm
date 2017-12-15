#include "../include/MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup) : _setup{ setup }
{
	_solutions.resize(_setup.population_size());

	for (unsigned int i = 0; i < _setup.population_size(); i++)
		_solutions[i] = new Solution{ pbm };
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

/**
Return the upper fitness of individuals in population

@return _upper_cost - returns the upper fitness of individuals in population
*/
unsigned int MyAlgorithm::upper_cost() const
{
	return _upper_cost;
}

/**
Return the lower fitness of individuals in population

@return _lower_cost - returns the lower fitness of individuals in population
*/
unsigned int MyAlgorithm::lower_cost() const
{
	return _lower_cost;
}

void MyAlgorithm::calculateProbabilities(vector<double>& _probabilities)
{

}
