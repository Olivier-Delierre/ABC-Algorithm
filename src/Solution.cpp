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
	Getter qui retourne le problème 
*/
Problem Solution::problem() const
{
	return _pbm;
}
/**
	Calcul et renvoie la meilleure fitness d'une solution (une solution est un vector de double)
*/
double Solution::calculate_fitness()
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
	return min;
}

std::vector<double> Solution::solution() const
{ return _solution; }
