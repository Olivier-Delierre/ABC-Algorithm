#include "../include/Solution.h"

/**
	Constructeur de solution selon un problème.
*/
Solution::Solution(const Problem& pbm) :
	_pbm{ pbm }
{ 
	_solution.resize(_pbm.dimension);
	initialize(); 
}

/**
	Constructeur par recopie.
*/
Solution::Solution(const Solution& sol) :
	_solution{ sol._solution },
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