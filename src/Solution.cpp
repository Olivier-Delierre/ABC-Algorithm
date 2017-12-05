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
	double sum{ 0 };
	
	for (unsigned int i = 0; i < _pbm.dimension() - 1; i++)
	{
		sum += pow((1 - _solution[i]), 2) + 100 * pow((_solution[i + 1] - pow(_solution[i], 2)), 2);
	}

	return sum;
}

double Solution::Rastrigin() const
{
	double sum{ 0 };

	for (unsigned int i = 0; i < _pbm.dimension(); i++)
	{
		sum += pow(_solution[i], 2) - 10 * cos(2 * M_PI * _solution[i]);
	}

	return 10 * _pbm.dimension() + sum;
}

double Solution::Ackley() const
{
	double a{ 20.0 }, b{ 0.2 }, c{ 2 * M_PI };
	
	double sum1{ 0 };
	double sum2{ 0 };

	sum1 += pow(_solution[0], 2);
	sum2 += cos(c * _solution[0]);

	return -a * exp(-b * sqrt( (1 / _pbm.dimension()) * sum1) ) - exp( (1 / _pbm.dimension()) * sum2) + a + exp(1);
}

double Solution::Schwefel() const
{
	double sum{ 0 };

	for (unsigned int i = 0; i < _pbm.dimension(); i++)
	{
		sum += _solution[i] * sin(sqrt(fabs(_solution[i])));
	}

	return 418.9829 * _pbm.dimension() - sum;
}

double Solution::Schaffer() const
{
	double f{ 0 };

	f = 0.5 + (pow( sin( pow(_solution[0], 2) + pow(_solution[1], 2)), 2) - 0.5) / 
				pow( 1 + 0.001 * ( pow(_solution[0], 2) + pow(_solution[1], 2) ), 2);

	return f;
}
