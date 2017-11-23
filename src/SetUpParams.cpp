#include "../include/SetUpParams.h"

/**
	Constructor to setup parameters for the Algorithm

	@param[in] independant_runs - number of independent runs
	@param[in] nb_evolution_steps - number of iteratrions per run
	@param[in] population_size - number of solutions in the population
	@param[in] solution_size - size of each particle
*/
SetUpParams::SetUpParams(const unsigned int independent_runs, const unsigned int nb_evolution_steps, const unsigned int population_size, const unsigned int solution_size) :
	_independent_runs{independent_runs},
	_nb_evolution_steps{nb_evolution_steps},
	_population_size{population_size},
	_solution_size{solution_size}
{}

/**
	Return the number of independent runs 

	@return _independant_runs - returns the number of indenpendent runs 
*/
const unsigned int   SetUpParams::independent_runs() const
{
	return _independent_runs;
}

/**
	Return the number of iterations per run

	@return _nb_evolution_steps - returns the number of iterations per run
*/
const unsigned int   SetUpParams::nb_evolution_steps() const
{
	return _nb_evolution_steps;
}

/**
	Return the number of solutions in the population

	@return _population_size - returns the number of solution in the population
*/
const unsigned int   SetUpParams::population_size() const
{
	return _population_size;
}

/**
	Return the size of each particle

	@return _solution_size - returns the size of each particle
*/
const unsigned int   SetUpParams::solution_size() const
{
	return _solution_size;
}



