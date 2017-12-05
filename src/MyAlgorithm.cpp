#include "../include/MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup) :
	_setup{ setup }
{
	_solutions.resize(_setup.population_size());

	for (unsigned int i = 0; i < _setup.population_size(); i++)
		_solutions[i] = new Solution{ pbm };
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
