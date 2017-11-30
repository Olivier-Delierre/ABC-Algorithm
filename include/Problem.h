#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <vector>

class Solution;

using namespace std;

class Problem
{
public:
	Problem(unsigned int dimension, double LLimit, double ULimit);
	//~Problem();

	

	friend ostream& operator<< (ostream& os, const Problem& pbm);
	friend istream& operator>> (istream& is, Problem& pbm);

	Problem& operator=  (const Problem& pbm);
	bool operator== (const Problem& pbm) const;
	bool operator!= (const Problem& pbm) const;

	//Direction direction() const; //Maximize or Minimize
	unsigned int dimension() const;
	double LowerLimit, UpperLimit;

private:
	//enum benchmarks{ Rosenbrock, Rastrigin, Ackley, Schwefel, Schaffer, Weierstrass };
	unsigned int _dimension;
};

#endif
