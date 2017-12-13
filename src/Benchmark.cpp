#include "../include/Benchmark.h"

double f(const Solution& solution, int num)
{
	switch (num)
	{
	case 1:
		return Rosenbrock(solution);
	case 2:
		return Rastrigin(solution);
	case 3:
		return Ackley(solution);
	case 4:
		return Schwefel(solution);
	case 5:
		return Schaffer(solution);
	case 6:
		return Weierstrass(solution);
	default:
		return Rosenbrock(solution);
	}
}

double Rosenbrock(const Solution &solution)	
{
	double sum{ 0 };
	
	for (unsigned int i = 0; i < solution.get_Problem().dimension() - 1; i++)
	{
		sum += pow((1 - solution.solution()[i]), 2) + 100 * pow((solution.solution()[i + 1] - pow(solution.solution()[i], 2)), 2);
	}

	return sum;
}

double Rastrigin(const Solution &solution)
{
	double sum{ 0 };

	for (unsigned int i = 0; i < solution.get_Problem().dimension(); i++)
	{
		sum += pow(solution.solution()[i], 2) - 10 * cos(2 * M_PI * solution.solution()[i]);
	}

	return 10 * solution.get_Problem().dimension() + sum;
}

double Ackley(const Solution &solution)
{
	double a{ 20.0 }, b{ 0.2 }, c{ 2 * M_PI };
	
	double sum1{ 0 };
	double sum2{ 0 };

	sum1 += pow(solution.solution()[0], 2);
	sum2 += cos(c * solution.solution()[0]);

	return -a * exp(-b * sqrt((1 / solution.get_Problem().dimension()) * sum1)) - exp((1 / solution.get_Problem().dimension()) * sum2) + a + exp(1);
}

double Schwefel(const Solution &solution)
{
	double sum{ 0 };

	for (unsigned int i = 0; i < solution.get_Problem().dimension(); i++)
	{
		sum += solution.solution()[i] * sin(sqrt(fabs(solution.solution()[i])));
	}

	return 418.9829 * solution.get_Problem().dimension() - sum;
}

double Schaffer(const Solution &solution)
{
	return 0;
}

double Weierstrass(const Solution &solution)
{
	return 0;
}
