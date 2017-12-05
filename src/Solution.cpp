#include "../include/Solution.h"

#include <climits>

/**
	Constructeur de solution selon un problème.
*/
Solution::Solution(const Problem& pbm) :
	_pbm{ pbm }
{ 
	_solution.resize(_pbm.dimension());
	initialize(); 
}

/**
	Constructeur par recopie.
*/
Solution::Solution(const Solution& sol) :
	_solution( sol._solution ),
	_current_fitness{ sol._current_fitness },
	_pbm{ sol._pbm }
{}

/**
	Destructeur par défaut
*/
Solution::~Solution()
{
}

/**
	Initialisation de chaque sources.
*/
void Solution::initialize()
{
	for (unsigned int i = 0; i < _solution.size(); i++)
		_solution[i] = _pbm.LowerLimit + (rand() % 1) * (_pbm.UpperLimit - _pbm.LowerLimit);
}

/**
	Renvoie la meilleure fitness de la solution.
*/
double Solution::fitness() const
{
	return _current_fitness;
}

/**
	Calcul et renvoie la meilleure fitness d'une solution (une solution est un vector de double)
*/
double Solution::get_fitness()
{
	//Calcul des fitness
	vector <double> fitness;
	fitness.resize(_solution.size());
	for (unsigned int i = 0; i < fitness.size(); i++)
	{
		double fx = f();
		if (fx >= 0) //si f(x)>=0 avec x étant une solution
			fitness[i] = 1 / (1 + fx);
		else
			fitness[i] = 1 + fabs(fx);
	}

	//Recherche de la meilleure fitness (la plus proche de zéro, comme toutes les valeurs sont positives il suffit de trouver le minimum)
	double min = INT_MAX;
	for (unsigned int i = 0; i < fitness.size(); i++)
	{
		if (fitness[i] < min)
			min = fitness[i];
	}
	return min;
}

double Solution::f() const
{
	return 0;
}

double Solution::Rosenbrock()	const
{
	int sum = 0;
	
	for (unsigned int i = 0; i < _solution.size() - 1; i++)
	{
		sum += pow((1 - _solution[i]), 2) + 100 * pow((_solution[i + 1] - pow(_solution[i], 2)), 2);
	}

	return sum;
}

double Solution::Rastrigin() const
{
	int sum = 0;

	for (unsigned int i = 0; i < _solution.size() - 1; i++)
	{
		sum += (10 * _solution.size()) + 1;
	}

	return sum;
}
