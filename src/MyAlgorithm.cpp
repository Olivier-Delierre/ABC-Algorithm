#include "../include/MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup) :
	_setup{ setup }
{
	initialize();
}

void MyAlgorithm::evaluate()
{
	for (int i = 0; i < _solutions.size(); i++)
		_fitness_values[i] = _solutions[i]->fitness();
}

void MyAlgorithm::initialize()
{
	_solutions.resize(_setup.population_size());

	for (int i = 0; i < _setup.population_size(); i++)
		_solutions[i] = new Solution{ pbm };
}
