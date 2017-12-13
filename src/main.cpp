#include "../include/MyAlgorithm.h"
#include "../include/Benchmark.h"

#define INDEPENDANT_RUNS 2000000
#define NB_EVOLUTION_STEPS 30
#define POPULATION_SIZE 30
#define SOLUTION_SIZE 30

/**
	Return le choix du benchmark
*/
int choixBenchmark()
{
	std::cout << "Choisissez le benchmark: (entrez un entier)" << std::endl;
	std::cout << "1- ROSENBROCK" << std::endl;
	std::cout << "2- RASTRIGIN" << std::endl;
	std::cout << "3- ACKLEY" << std::endl;
	std::cout << "4- SCHWEFEL" << std::endl;
	std::cout << "5- SCHAFFER" << std::endl;
	std::cout << "6- WEIERSTRASS" << std::endl;
	int choix;
	std::cin >> choix;
	while (choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6)
	{
		std::cout << "Veuillez saisir un entier compris entre 1 et 6." << std::endl;
		std::cout << std::endl;
		std::cout << "Choisissez le benchmark: (entrez un entier)" << std::endl;
		std::cout << "1- ROSENBROCK" << std::endl;
		std::cout << "2- RASTRIGIN" << std::endl;
		std::cout << "3- ACKLEY" << std::endl;
		std::cout << "4- SCHWEFEL" << std::endl;
		std::cout << "5- SCHAFFER" << std::endl;
		std::cout << "6- WEIERSTRASS" << std::endl;
	}
	return choix;
	fonction(choix);
}


int main()
{
	srand(time(0));
	int numBenchmark = choixBenchmark();
	Problem P{ SOLUTION_SIZE, numBenchmark };
	SetUpParams params{ INDEPENDANT_RUNS, NB_EVOLUTION_STEPS, POPULATION_SIZE, SOLUTION_SIZE };
	MyAlgorithm ABC{ P, params };
	ABC.evolution();
	system("pause");
	cout << "0" << std::endl;
}
