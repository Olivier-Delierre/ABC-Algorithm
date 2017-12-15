#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include "Problem.h"
#include "Solution.h"
#include "SetUpParams.h"

class MyAlgorithm
{
private:
	vector<Solution*> _solutions;     // individuals in population
	vector <double> _fitness_values;
	const SetUpParams& _setup;
	unsigned int _upper_cost, _lower_cost; // lower and upper fitness of individuals in population
	vector<double> _probabilities; // probabilities of food sources to be chosen

	vector<unsigned int> _trial; 
public:
	MyAlgorithm(const Problem& pbm, const SetUpParams& setup);
	~MyAlgorithm();

	void initialize();
	friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);
	friend istream& operator>> (istream& is, MyAlgorithm& myAlgo);
	MyAlgorithm& operator= (const MyAlgorithm& myAlgo);
	const SetUpParams& setup() const;
	
	
	void sendEmployedBees();
	void sendOnLookerBees();
	void sendScoutBees();
	double evolution();

	// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
	void evaluate();

	const vector<Solution*>& solutions() const;
	double fitness(const int index) const;
	int upper_cost() const;
	int lower_cost() const;
	Solution& solution(const unsigned int index) const;
	double fitness(const unsigned int index) const;


	double best_cost() const;
	double worst_cost() const;
	Solution& best_solution() const;
	Solution& worst_solution() const;

	void evolution(int iter); /*makes an evolution step*/
	void calculateProbabilities();

};

#endif
