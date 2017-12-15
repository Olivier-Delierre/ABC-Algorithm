#include "../include/MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup) : _setup{ setup }
{
	_solutions.resize(_setup.population_size());

	for (unsigned int i = 0; i < _setup.population_size(); i++)
		_solutions[i] = new Solution{ pbm };
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
