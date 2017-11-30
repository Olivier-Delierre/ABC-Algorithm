#include "../include/Solution.h"

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
	_pbm{ sol._pbm },
	_current_fitness{ sol._current_fitness }
{}

/**
	Initialisation de chaque sources.
*/
void Solution::initialize()
{
	for (int i = 0; i < _solution.size(); i++)
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
	for (int i = 0; i < fitness.size(); i++)
	{
		double fx = f();
		if (fx >= 0) //si f(x)>=0 avec x étant une solution
			fitness[i] = 1 / (1 + fx);
		else
			fitness[i] = 1 + fabs(fx);
	}

	//Recherche de la meilleure fitness (la plus proche de zéro, comme toutes les valeurs sont positives il suffit de trouver le minimum)
	double min = INT_MAX;
	for (int i = 0; i < fitness.size(); i++)
	{
		if (fitness[i] < min)
			min = fitness[i];
	}
	return min;
}