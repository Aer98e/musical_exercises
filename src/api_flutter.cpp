#include "exercises_functions.h"

#include <string>
#include <cstdlib>
#include <cstring>

const char* sendStringToHeap(const std::string& str){
    char* spaceToString = static_cast<char*>(std::malloc(str.lenght() + 1))
    
    if(spaceToString == nullptr){
        return nullptr;
    }

    std::strcpy(spaceToString, str.c_str());
    return spaceToString;
}

extern "C"{
    char* byWriteScales_C(int amount){
        std::string jsonExercises = byWriteScales_Nova(amount);
        return sendStringToHeap(jsonExercises);
    }

    char* byRecognizeIntervalsGrades_C(int amount){
        std::string jsonExercises = byRecognizeIntervalsGrades_Nova(amount);
        return sendStringToHeap(jsonExercises);
    }

    char* byRecognizeIntervalsNotes_C(int amount, int OctMin, int OctMax){
        std::string jsonExercises = byRecognizeIntervalsNotes_Nova(amount, OctMin, OctMax);
        return sendStringToHeap(jsonExercises);
    }

    char* byFormIntervals_C(int amount, int numElements){
        std::string jsonExercises = byFormIntervals(amount, numElements);
        return sendStringToHeap(jsonExercises);
    }

    char* byFormAugmentedSixthChords_C(int amount){
        std::string jsonExercises = byFormAugmentedSixthChords_Nova(amount);
        return sendStringToHeap(jsonExercises);
    }

    void freeCharPointer(char* ptr){
        std::free(ptr);
    }
}

