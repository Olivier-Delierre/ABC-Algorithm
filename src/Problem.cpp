#include "../include/Problem.h"

Problem::Problem(unsigned int dimension, int numBenchmark) : _dimension{ dimension }, _numBenchmark{numBenchmark}
{
	
}

unsigned int Problem::dimension() const
{ return _dimension; }
