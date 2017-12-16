#include "SetUpParams.h"

SetUpParams::SetUpParams(unsigned int independent_runs, unsigned int nb_evolution_steps, unsigned int population_size, unsigned int solution_size, unsigned int max_trials) :
	_independent_runs{ independent_runs },
	_nb_evolution_steps{ nb_evolution_steps },
	_population_size{ population_size },
	_solution_size{ solution_size },
	_max_trials{ max_trials }
{}

SetUpParams::~SetUpParams()
{}

unsigned int SetUpParams::independent_runs() const
{
	return _independent_runs;
}

unsigned int SetUpParams::nb_evolution_steps() const
{
	return _nb_evolution_steps;
}

unsigned int SetUpParams::population_size() const
{
	return _population_size;
}

unsigned int SetUpParams::solution_size() const
{
	return _solution_size;
}

unsigned int SetUpParams::max_trials() const
{
	return _max_trials;
}
