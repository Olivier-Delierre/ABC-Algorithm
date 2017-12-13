#include "../include/Benchmark.h"

double Rosenbrock(const Solution &solution)	
{
	double sum{ 0 };
	
	for (unsigned int i = 0; i < solution._pbm.dimension() - 1; i++)
	{
		sum += pow((1 - solution[i]), 2) + 100 * pow((solution[i + 1] - pow(solution[i], 2)), 2);
	}

	return sum;
}

double Rastrigin(const Solution &solution)
{
	double sum{ 0 };

	for (unsigned int i = 0; i < _pbm.dimension(); i++)
	{
		sum += pow(_solution[i], 2) - 10 * cos(2 * M_PI * _solution[i]);
	}

	return 10 * _pbm.dimension() + sum;
}

double Ackley(const Solution &solution)
{
	double a{ 20.0 }, b{ 0.2 }, c{ 2 * M_PI };
	
	double sum1{ 0 };
	double sum2{ 0 };

	sum1 += pow(_solution[0], 2);
	sum2 += cos(c * _solution[0]);

	return -a * exp(-b * sqrt( (1 / _pbm.dimension()) * sum1) ) - exp( (1 / _pbm.dimension()) * sum2) + a + exp(1);
}

double Schwefel(const Solution &solution)
{
	double sum{ 0 };

	for (unsigned int i = 0; i < _pbm.dimension(); i++)
	{
		sum += _solution[i] * sin(sqrt(fabs(_solution[i])));
	}

	return 418.9829 * _pbm.dimension() - sum;
}

double Schaffer(const Solution &solution)
