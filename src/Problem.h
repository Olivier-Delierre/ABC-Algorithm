#ifndef PROBLEM_H
#define PROBLEM_H

class Solution;

class Problem
{
public:
	/**
	 * Constructor with a dimension and a benchmark number.
	 * The constructor initialize the _dimension var and set the lower and upper limits
	 * given the choosen benchmark number.
	 *
	 * \params dimension The dimension of the problem
	 * \params benchmark_number The number of the benchmark.
	 */
	Problem(unsigned int dimension, int benchmark_number);
	
	/// Default destructor
	~Problem();

	/**
	 * Returns the dimension of the problem.
	 *
	 * \returns the dimension of the problem.
	 */
	unsigned int dimension() const;

	/**
	 * Returns the lower limit of the problem.
	 *
	 * \returns the lower limit of the problem.
	 */
	double lower_limit() const;

	/**
	 * Returns the upper limit of the problem.
	 *
	 * \returns the upper limit of the problem.
	 */
	double upper_limit() const;

	/**
	 * Returns the number of the choosen benchmark.
	 *
	 * \returns the number of the choosen benchmark.
	 */
	int benchmark_number() const;
private:
	/// The dimension of the problem.
	unsigned int _dimension;
	/// The two limits of the problem (which defines the function used by the benchmark).
	double _lower_limit, _upper_limit;
	/// The number of the choosen benchmark.
	int _benchmark_number;
};

#endif
