#pragma once
#include <vector>
#include <string>
#include <utility>

int generate_rand_number(int max, int min = 0);
int generate_rand_number(std::size_t max, std::size_t min=0);
std::pair<std::string, std::vector<int>> getRandPattern();