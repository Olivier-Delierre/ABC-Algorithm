#include "../include/MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup) :
	_setup{ setup }
{
	_solutions.resize(_setup.population_size());

	for (unsigned int i = 0; i < _setup.population_size(); i++)
		_solutions[i] = new Solution{ pbm };
}