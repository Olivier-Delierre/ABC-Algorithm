#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <iomanip>
#include <iostream>

#include "SetUpParams.h"
#include "Solution.h"

class MyAlgorithm
{
public:
	/**
	 * Constructor with the problem of the algorithm, and the parameters.
	 *
	 * The constructor initializes all vectors, fill the parameters,
	 * and initializes all solutions of the algorithm and calculate the fitness
	 * of all solutions using the evaluate function.
	 */
	MyAlgorithm(const Problem& problem, const SetUpParams& params);
	
	/// Default destructor
	~MyAlgorithm();

	/**
	 * Initializes the algorithm.
	 *
	 * That means initializing all solutions of the algorithm, and
	 * filling the fitness' vector for the first time using the evaluate function.
	 */
	void initialize();

	/**
	 * Evaluates the algorithm.
	 *
	 * That means filling the fitness' vector.
	 */
	void evaluate();


	/**
	 * Start the algorithm. The evolution process consists of multiple steps :
	 * 	- The initialization of the algorithm ;
	 * 	- For each evolution steps :
	 * 		- Evaluate ;
	 * 		- Display informations about the current evolution step ;
	 * 		- Sending employed bees ;
	 * 		- Sending onlooker bees ;
	 * 		- Sending scout bees.
	 * 	- Display the information about the last evolution step.
	 *	Times the number of independant runs set by the parameters.
	 */	
	void evolution();

	/**
	 * Returns the vector containing all solutions.
	 *
	 * \returns the vector containing all solutions.
	 */	
	std::vector<Solution*> solutions() const;

	/**
	 * Returns the vector which contains the fitness of all solutions.
	 *
	 * \returns the vector which contains the fitness of all solutions.
	 */
	std::vector<double> fitness_values() const;

	/**
	 * Returns the upper cost of the algorithm.
	 *
	 * \returns the upper cost of the algorithm.
	 */
	unsigned int upper_cost() const;

	/**
	 * Returns the lower cost of the algorithm.
	 *
	 * \returns the lower cost of the algorithm.
	 */
	unsigned int lower_cost() const;

	double best_cost() const;
	double worst_cost() const;

	/**
	 * Returns the best solution of the algorithm.
	 *
	 * \returns the best solution of the algorithm.
	 */
	Solution& best_solution() const;

	/**
	 * Returns the worst solution of the algorithm.
	 *
	 * \returns the worst solution of the algorithm.
	 */
	Solution& worst_solution() const;
private:
	/**
	 * Generate a new value for each particles of a solution.
	 *
	 * If the new value is better than the previous :
	 * 	- The previous value is replaced by the new ;
	 * 	- The counter of trials for the solution returned to 0.
	 *
	 * Else, the function increments the counter of trials.
	 */
	void send_employed_bees();

	/**
	 * 
	 */
	void send_onlooker_bees();

	/**
	 * Check if a solution have passed the max number of trial.
	 * If it is the case, the solution is reinitialized.
	 */
	void send_scout_bees();
	
	/**
	 * Calculate the probabilities for each solutions to be choose
	 * by the onlooker bees using a simple mathematic function.
	 */
	void calculate_probabilities();

	/// The parameters of the algorithm.
	const SetUpParams& _params;
	/// The vector which contains the solutions.
	std::vector<Solution*> _solutions;
	/// The vector which contains the fitness of all solutions.
	std::vector<double> _fitness_values;
	/// The vector which contains the probabilities of being caught by the onlooker bees for the solutions.
	std::vector<double> _probabilities;
	/// The vector which contains the number of trials of all solutions.
	std::vector<unsigned int> _trials; 
	/// Both upper and lower costs of the algorithm.
	unsigned int _upper_cost, _lower_cost;
};

#endif
