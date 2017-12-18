#ifndef BENCHMARK_H
#define BENCHMARK_H


class Solution;

namespace Benchmark {
/**
 * Returns the result of the fonction used by the choosen benchmark.
 *
 * \params solution A solution.
 *
 * \returns the result of the choosen function.
 */
double f(const Solution& solution, int num);

/**
 * Returns the result of the Rosenbrock function applied on the solution.
 *
 * \params solution A solution.
 *
 * \returns the result of the function.
 */
double Rosenbrock(const Solution &solution);

/**
 * Returns the result of the Rastrigin function applied on the solution.
 *
 * \params solution A solution.
 *
 * \returns the result of the function.
 */
double Rastrigin(const Solution &solution);

/**
 * Returns the result of the Ackley function applied on the solution.
 *
 * \params solution A solution.
 *
 * \returns the result of the function.
 */
double Ackley(const Solution &solution);

/**
 * Returns the result of the Schwefel function applied on the solution.
 *
 * \params solution A solution.
 *
 * \returns the result of the function.
 */
double Schwefel(const Solution &solution);

/**
 * Returns the result of the Schaffer function applied on the solution.
 *
 * \params solution A solution.
 *
 * \returns the result of the function.
 */
double Schaffer(const Solution &solution);

/**
 * Returns the result of the Weierstrass function applied on the solution.
 *
 * \params solution A solution.
 *
 * \returns the result of the function.
 */
double Weierstrass(const Solution &solution);
}
#endif
