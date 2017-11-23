#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

#include "MyAlgorithm.h"
#include "Problem.h"

class Solution
{
	//contient la déclaration d'une solution
public:
	Solution(const Problem& pbm);
	Solution(const Solution& sol);
	~Solution();

	friend ostream& operator<< (ostream& os, const Solution& sol);
	friend istream& operator>> (istream& is, Solution& sol);

	const Problem& pbm() const;

	Solution& operator=  (const Solution& sol);
	bool operator== (const Solution& sol) const;
	bool operator!= (const Solution& sol) const;

	void initialize();
	double fitness();
	double get_fitness();

	unsigned int size() const;

	vector<double>& solution();

	double& position(const int index); //retournera une position du tableau _solution
	void  position(const int index, const double value);


private:
	vector<double> _solution;
	double _current_fitness;
	const Problem& _pbm;
};

#endif