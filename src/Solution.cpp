#include "../include/Solution.h"

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
{ 
	return _solution; 
}

double Solution::current_fitness() const
{
	return _current_fitness;
}

Problem Solution::problem() const
{
	return _problem;
}

void Solution::initialize()
{
	for (unsigned int i = 0; i < _solution.size(); i++)
		_solution[i] = _problem.LowerLimit + (rand() % 1) * (_problem.UpperLimit - _problem.LowerLimit);
}

void Solution::calculate_fitness()
{
	//Calcul des fitness
	vector <double> fitness;
	fitness.resize(_solution.size());
	for (unsigned int i = 0; i < fitness.size(); i++)
	{
		//double fx = f();
		//if (fx >= 0) //si f(x)>=0 avec x étant une solution
			//fitness[i] = 1 / (1 + fx);
		//else
			//fitness[i] = 1 + fabs(fx);
	}

	//Recherche de la meilleure fitness (la plus proche de zéro, comme toutes les valeurs sont positives il suffit de trouver le minimum)
	double min = INT_MAX;
	for (unsigned int i = 0; i < fitness.size(); i++)
	{
		if (fitness[i] < min)
			min = fitness[i];
	}
}

