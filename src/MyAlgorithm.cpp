#include "../include/MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup) : _solutions{}, _trial{}, _fitness_values{}, _setup{ setup }
{
	_solutions.resize(_setup.population_size());
	_fitness_values.resize(_setup.population_size());
	for (int i = 0; i<d_setup.population_size(); ++i)
	{
		_solutions[i] = new Solution{ pbm };
		_fitnessValues[i] = _solutions[i]->fitness();
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

double MyAlgorithm::evolution()
{
	for (int i = 0; i < INDEPENDANT_RUNS; i++)
	{
		initialize();
		for (int i = 0; i < NB_EVOLUTION_STEPS; i++)
		{
			sendEmployeedBees();
			sendOnLookerBees();
			sendScoutBees();
		}
	}
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
