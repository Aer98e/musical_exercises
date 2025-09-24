#include "music_utils.h"
#include "data_music.h"
#include <random>
#include <cstddef>

int generate_rand_number(int max, int min){
    //Los margenes son inclusivos
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribucion(min, max);

	return distribucion(gen);
}

int generate_rand_number(std::size_t max, std::size_t min){
    int minI{static_cast<int>(min)};
    int maxI{static_cast<int>(max)};
    //Los margenes son inclusivos
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribucion(minI, maxI);

	return distribucion(gen);
}

std::pair<std::string, std::vector<int>> getRandPattern() {
    int sizePattern { static_cast<int>(dtMusic::Patterns.size()) };
    int randSelect { generate_rand_number(sizePattern - 1) };
    auto iter { dtMusic::Patterns.begin() };
    std::advance(iter, randSelect);
    return {iter->first, iter->second};
}