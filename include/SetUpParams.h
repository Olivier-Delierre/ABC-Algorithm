#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H

#include <iostream>

using namespace std;

class SetUpParams
{
	//ici vous devez mettre quelques paramètres tels que :

private:
	unsigned int   _independent_runs;         //number of independent runs
	unsigned int   _nb_evolution_steps;       // number of iterations per run
	unsigned int   _population_size;		// number of solutions in the population
	unsigned int   _solution_size;	        // size of each particle

public:
	SetUpParams(const unsigned int independent_runs, const unsigned int nb_evolution_steps, const unsigned int population_size, const unsigned int solution_size);

	const unsigned int   independent_runs() const;
	const unsigned int   nb_evolution_steps() const;
	const unsigned int   population_size() const;
	const unsigned int   solution_size() const;

	//~SetUpParams();
};

#endif
