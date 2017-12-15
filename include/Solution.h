#ifndef SOLUTION_H
#define SOLUTION_H

#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>
#include <climits>
#include "Problem.h"

class Solution
{
	//contient la déclaration d'une solution
public:
	Solution(const Problem& pbm);
	Solution(const Solution& sol);
	~Solution();

	const Problem& pbm() const;

	Solution& operator=  (const Solution& sol);
	bool operator== (const Solution& sol) const;
	bool operator!= (const Solution& sol) const;

	void initialize();
	double fitness() const;
	double calculate_fitness();
	Problem problem() const;

	unsigned int size() const;

	std::vector<double> solution() const;

	double& position(const int index); //retournera une position du tableau _solution
	void  position(const int index, const double value);


private:
	std::vector<double> _solution;
	double _current_fitness;
	const Problem& _pbm;
};

#endif
