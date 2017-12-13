#include "../include/Problem.h"

Problem::Problem(unsigned int dimension, int numBenchmark) : _dimension{ dimension }, _numBenchmark{ numBenchmark }
{
	switch (numBenchmark)
	{
	case 1:
		LowerLimit=-5, UpperLimit=10;
		break;
	case 2:
		LowerLimit=-5.12, UpperLimit=5.12;
		break;
	case 3:
		LowerLimit=-32.768, UpperLimit=32.768;
		break;
	case 4:
		LowerLimit=-500, UpperLimit=500;
		break;
	case 5:
		LowerLimit=-100, UpperLimit=100;
		break;
	case 6:
		LowerLimit=-10, UpperLimit=10;
		break;
	default:
		LowerLimit=-5, UpperLimit=10;
		break;
	}
}

unsigned int Problem::dimension() const
{ return _dimension; }
