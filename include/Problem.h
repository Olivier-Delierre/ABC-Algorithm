#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>

using namespace std;

class Problem
{
public:
	Problem(unsigned int dimension, double LLimit, double ULimit);
	//~Problem();

	double f(const vector <Solution*> &Solution) const;
	double Rosenbrock(const vector <Solution*> &Solution) const;
	double Rastrigin(const vector <Solution*> &Solution) const;
	double Ackley(const vector <Solution*> &Solution) const;
	double Schwefel(const vector <Solution*> &Solution) const;
	double Schaffer(const vector <Solution*> &Solution) const;
	double Weierstrass(const vector <Solution*> &Solution) const;

	friend ostream& operator<< (ostream& os, const Problem& pbm);
	friend istream& operator>> (istream& is, Problem& pbm);

	Problem& operator=  (const Problem& pbm);
	bool operator== (const Problem& pbm) const;
	bool operator!= (const Problem& pbm) const;

	//Direction direction() const; //Maximize or Minimize
	unsigned int dimension() const;
	double LowerLimit, UpperLimit;

private:
	enum benchmarks{ Rosenbrock, Rastrigin, Ackley, Schwefel, Schaffer, Weierstrass };
	unsigned int _dimension;
};

#endif