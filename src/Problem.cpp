#include "Problem.h"

Problem::Problem(unsigned int dimension, int benchmark_number) : 
	_dimension{ dimension }, 
	_benchmark_number{ benchmark_number }
{
	switch (_benchmark_number)
	{
	case 1:
		_lower_limit=-5, _upper_limit=10;
		break;
	case 2:
		_lower_limit=-5.12, _upper_limit=5.12;
		break;
	case 3:
		_lower_limit=-32.768, _upper_limit=32.768;
		break;
	case 4:
		_lower_limit=-500, _upper_limit=500;
		break;
	case 5:
		_lower_limit=-100, _upper_limit=100;
		break;
	case 6:
		_lower_limit=-10, _upper_limit=10;
		break;
	default:
		_lower_limit=-5, _upper_limit=10;
		break;
	}
}

Problem::~Problem()
{}

unsigned int Problem::dimension() const
{ return _dimension; }

double Problem::lower_limit() const
{ return _lower_limit; }

double Problem::upper_limit() const
{ return _upper_limit; }

int Problem::benchmark_number() const
{ return _benchmark_number; }
