#include "Benchmark.h"
#include "Solution.h"

#include <iostream>

namespace Benchmark {
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
	
	for (unsigned int i = 0; i < solution.problem().dimension() - 1; i++)
	{
		sum += pow((1 - solution.solution()[i]), 2) + 100 * pow((solution.solution()[i + 1] - pow(solution.solution()[i], 2)), 2);
	}

	return sum;
}

double Rastrigin(const Solution &solution)
{
	double sum{ 0 };

	for (unsigned int i = 0; i < solution.problem().dimension(); i++)
	{
		sum += pow(solution.solution()[i], 2) - 10 * cos(2 * M_PI * solution.solution()[i]);
	}

	return 10 * solution.problem().dimension() + sum;
}

double Ackley(const Solution &solution)
{
	double a{ 20.0 }, b{ 0.2 }, c{ 2.0 * M_PI };
	
	double sum1{ 0.0 };
	double sum2{ 0.0 };

    for (unsigned int i = 0; i < solution.problem().dimension(); i++)
    {
	    sum1 += pow(solution.solution()[i], 2);
        sum2 += cos(c * solution.solution()[i]);
    }

	return -a * exp(-b * sqrt((1.0 / solution.problem().dimension()) * sum1)) - exp((1.0 / solution.problem().dimension()) * sum2) + a + exp(1.0);
}

double Schwefel(const Solution &solution)
{
	double sum{ 0 };

	for (unsigned int i = 0; i < solution.problem().dimension(); i++)
	{
		sum += (solution.solution()[i] * sin(sqrt(fabs(solution.solution()[i]))));
	}

    double result = 418.9829 * solution.problem().dimension() - sum;
	return result;
}

double Schaffer(const Solution &solution)
{

	double x1 = solution.solution()[1];
	double x2 = solution.solution()[2];

	double fact1 = pow((sin(x1*x1 - x2*x2)), 2) - 0.5;
	double fact2 = pow((1 + 0.001*(x1*x1 + x2*x2)), 2);

	double y = 0.5 + fact1 / fact2;

	return y;
}

double Weierstrass(const Solution &solution)
{
	double a{ 0.5 }, b{ 12 };

	double sum{ 0 };

	for (unsigned int i = 0; i < solution.problem().dimension(); i++)
	{
		for (unsigned int j = 0; j <= 20; j++)
		{
			sum += pow(a, j) * cos(M_PI * pow(b, j) * solution.solution()[i]);
		}
	}
	return sum;
}
}
