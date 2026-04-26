#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "task_t1.h"

int main() {
    const int iterations = 1000;
    std::ofstream outfile("execution_times.csv");

    //initialisation aléatoire
    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, time(NULL));

    std::cout << "Simulation en cours " << iterations << std::endl;

    for (int i = 0; i < iterations; ++i) {
		//chrono détaillé
        auto start = std::chrono::high_resolution_clock::now();

        task_t1(state);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        //on écrit le temps en secondes dans le CSV
        outfile << diff.count() << "\n";
    }

    outfile.close();
    gmp_randclear(state);
    std::cout << "Fichier execution_times.csv généré." << std::endl;

    return 0;
}