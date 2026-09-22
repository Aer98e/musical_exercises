#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <map>

namespace dtMusic
{
    extern std::vector<std::string> noteNames;

    extern std::vector<std::string> gradeWName;
	
	extern std::vector<std::string> gradeAwName;

    extern std::vector<std::string> intervals;

	extern std::vector<std::string> scalesNameTypes;

	extern std::vector<std::string> directions;

	extern std::unordered_map<std::string, std::vector<int>> Patterns;

	extern std::map<int, int> valueIntervales;

	extern std::vector<std::string> typesAugmentChords;
}