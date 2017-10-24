#include "../include/Problem.h"

Problem::Problem(unsigned int dimension, double LLimit, double ULimit) :
	_dimension{ dimension },
	LowerLimit{ LLimit },
	UpperLimit{ ULimit }
{}