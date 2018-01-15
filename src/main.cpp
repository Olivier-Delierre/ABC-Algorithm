/** 
 *  @file    main.cpp
 *  @author  Olivier Delierre, Michael Gerwill, Antonin Leclerc and Ilyasse Tissafi.
 *  @date    15/12/2017
 *  @version 1.0
 *  
 *  @brief Calculate the minimum of a function using the ABC algorithm.
 *
 *  @section DESCRIPTION
 *  
 *	This program use the Artificial Bee Colony algorithm in order to obtain
 *	the x value for certain function in order to obtain the minimum of them.
 *
 *	At the moment, you can calculate the minimum of 6 functions, which
 *	are mentioned in the Benchmark's header file.
 *  Here's the list :
 *  	- Ackley
 *  	- Rastrigin
 *  	- Rosenbrock
 *  	- Schaffer
 *  	- Schwefel
 *  	- Weierstrass
 */


#include <ctime>

#include "Benchmark.h"
#include "MyAlgorithm.h"

#define INDEPENDANT_RUNS 2000000
#define NB_EVOLUTION_STEPS 30
#define POPULATION_SIZE 30
#define SOLUTION_SIZE 30
#define MAX_TRIALS 100

using namespace std;

/**
	Returns the choice of the Benchmark.

	\returns the choice of the Benchmark.
*/
int choice_of_benchmark()
{
	cout << "Choose your Benchmark : " << endl;
	cout << "1- ROSENBROCK" << endl;
	cout << "2- RASTRIGIN" << endl;
	cout << "3- ACKLEY" << endl;
	cout << "4- SCHWEFEL" << endl;
	cout << "5- SCHAFFER" << endl;
	cout << "6- WEIERSTRASS" << endl;
	int choice;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
	{
		cout << "Please choose a number between 1 and 6." << endl;
		cout << endl;
		cout << "Choose your Benchmark : " << endl;
		cout << "1- ROSENBROCK" << endl;
		cout << "2- RASTRIGIN" << endl;
		cout << "3- ACKLEY" << endl;
		cout << "4- SCHWEFEL" << endl;
		cout << "5- SCHAFFER" << endl;
		cout << "6- WEIERSTRASS" << endl;
	}
	return choice;
}

int main()
{
	srand(time(0));
	int benchmark_number = choice_of_benchmark();
	Problem P{ SOLUTION_SIZE, benchmark_number };
	SetUpParams params{ INDEPENDANT_RUNS, NB_EVOLUTION_STEPS, POPULATION_SIZE, SOLUTION_SIZE, MAX_TRIALS };
	MyAlgorithm ABC{ P, params };
	ABC.evolution();

	// Change if it's Windows or UNIX.	
	#ifdef _WIN32
		system("pause");
	#else
		cin.ignore(1024, '\n');
		cout << "Press enter to continue ...";
		cin.get();
	#endif
	cout << "0" << endl;
}
