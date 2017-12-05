#include "../include/Problem.h"

Problem::Problem(unsigned int dimension, double LLimit, double ULimit) :
	LowerLimit{ LLimit },
	UpperLimit{ ULimit },
	_dimension{ dimension }
{}

unsigned int Problem::dimension() const
{ return _dimension; }
