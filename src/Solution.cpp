#include "Solution.h"

Solution::Solution(const Problem& problem) :
	_problem{ problem }
{ 
	_solution.resize(_problem.dimension());
	initialize(); 
}

Solution::Solution(const Solution& solution) :
	_solution( solution._solution ),
	_current_fitness{ solution._current_fitness },
	_problem{ solution._problem }
{}

Solution::~Solution()
{}

std::vector<double> Solution::solution() const
{ return _solution; }

double Solution::current_fitness() const
{ return _current_fitness; }

Problem Solution::problem() const
{ return _problem; }

void Solution::initialize()
{
	for (unsigned int i = 0; i < _solution.size(); i++)
		_solution[i] = _problem.lower_limit() + (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * (_problem.upper_limit() - _problem.lower_limit());
}

void Solution::set_value_to_index(double value, int index)
{
    _solution[index] = value;
}

double Solution::return_fitness()
{
    return Benchmark::f(*this, _problem.benchmark_number());
}

void Solution::calculate_fitness()
{
	std::vector<double> fitness;
	fitness.resize(_solution.size());
	double f = Benchmark::f(*this, _problem.benchmark_number());
	for (unsigned int i = 0; i < fitness.size(); i++)
	{
		if (f >= 0)
			fitness[i] = 1 / (1 + f);
		else
			fitness[i] = 1 + fabs(f);
	}

	_current_fitness = f;
}

