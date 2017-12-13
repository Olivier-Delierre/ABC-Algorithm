#ifndef BENCHMARK_H
#define BENCHMARK_H

#define _USE_MATH_DEFINES

#include "MyAlgorithm.h"

double Rosenbrock(const Solution &solution);
double Rastrigin(const Solution &solution);
double Ackley(const Solution &solution);
double Schwefel(const Solution &solution);
double Schaffer(const Solution &solution);
double Weierstrass(const Solution &solution);


#endif
