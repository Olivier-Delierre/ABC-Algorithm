#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H

class SetUpParams
{
public:
	/**
	 * Constructor with all parameters.
	 *
	 * \params independent_runs An integer which contains the number of independant runs
	 * \params nb_evolution_steps An integer which contains the number of iterations per run
	 * \params population_size An integer which contains the size of the population
	 * \params solution_size An integer which contains the size of each particles
	 * \params max_trials An integer which contains the maximum number of trials.
	 */
	SetUpParams(unsigned int independent_runs, unsigned int nb_evolution_steps, unsigned int population_size, unsigned int solution_size, unsigned int max_trials);
	/// Default destructor
	~SetUpParams();
	
	/**
	 * Returns the number of independant runs.
	 *
	 * \returns the number of independant runs.
	 */
	unsigned int independent_runs() const;	
	
	/**
	 * Returns the number of iterations per run.
	 *
	 * \returns the number of iterations per run.
	 */
	unsigned int nb_evolution_steps() const;

	/**
	 * Returns the size of the population.
	 *
	 * \returns the size of the population.
	 */
	unsigned int population_size() const;

	/**
	 * Returns the size of each particles.
	 *
	 * \returns the size of each particles.
	 */
	unsigned int solution_size() const;

	/**
	 * Returns the maximum number of trials.
	 *
	 * \returns the maximum number of trials.
	 */
	unsigned int max_trials() const;

	//~SetUpParams();
private:
	/// Number of independent runs.
	unsigned int _independent_runs;
	/// Number of iterations per run.
	unsigned int _nb_evolution_steps;
	/// Size of the population.
	unsigned int _population_size;
	/// Size of each particle.
	unsigned int _solution_size;
	/// Max number of trials.
	unsigned int _max_trials;
};

#endif
