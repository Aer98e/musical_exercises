#include <random>
#include <iostream>

int generate_rand_number(int max, int min = 0){
    //Los margenes son inclusivos
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribucion(min, max);

	return distribucion(gen);
}