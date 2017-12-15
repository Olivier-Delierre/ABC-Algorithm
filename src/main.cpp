#include <ctime>

#include "../include/MyAlgorithm.h"
#include "../include/Benchmark.h"

#define INDEPENDANT_RUNS 2000000
#define NB_EVOLUTION_STEPS 30
#define POPULATION_SIZE 30
#define SOLUTION_SIZE 30

using namespace std;

/**
	Return le choix du benchmark
*/
int choixBenchmark()
{
	cout << "Choisissez le benchmark: (entrez un entier)" << endl;
	cout << "1- ROSENBROCK" << endl;
	cout << "2- RASTRIGIN" << endl;
	cout << "3- ACKLEY" << endl;
	cout << "4- SCHWEFEL" << endl;
	cout << "5- SCHAFFER" << endl;
	cout << "6- WEIERSTRASS" << endl;
	int choix;
	cin >> choix;
	while (choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6)
	{
		cout << "Veuillez saisir un entier compris entre 1 et 6." << endl;
		cout << endl;
		cout << "Choisissez le benchmark: (entrez un entier)" << endl;
		cout << "1- ROSENBROCK" << endl;
		cout << "2- RASTRIGIN" << endl;
		cout << "3- ACKLEY" << endl;
		cout << "4- SCHWEFEL" << endl;
		cout << "5- SCHAFFER" << endl;
		cout << "6- WEIERSTRASS" << endl;
	}
	return choix;
}

int main()
{
	srand(time(0));
	int numBenchmark = choixBenchmark();
	Problem P{ SOLUTION_SIZE, numBenchmark };
	SetUpParams params{ INDEPENDANT_RUNS, NB_EVOLUTION_STEPS, POPULATION_SIZE, SOLUTION_SIZE };
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
