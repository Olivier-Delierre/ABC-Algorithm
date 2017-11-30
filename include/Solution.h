#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <cmath>
#include "Problem.h"

class Solution
{
	//contient la déclaration d'une solution
public:
	Solution(const Problem& pbm);
	Solution(const Solution& sol);
	~Solution();

	double f() const;
	double Rosenbrock() const;
	double Rastrigin() const;
	double Ackley() const;
	double Schwefel() const;
	double Schaffer() const;
	double Weierstrass() const;

	const Problem& pbm() const;

	Solution& operator=  (const Solution& sol);
	bool operator== (const Solution& sol) const;
	bool operator!= (const Solution& sol) const;

	void initialize();
	double fitness() const;
	double get_fitness();

	unsigned int size() const;

	std::vector<double>& solution() const;

	double& position(const int index); //retournera une position du tableau _solution
	void  position(const int index, const double value);


private:
	std::vector<double> _solution;
	double _current_fitness;
	const Problem& _pbm;
};

#endif