#pragma once

#if defined(_WIN32)
    #define MUSICAL_API __declspec(dllexport)
#else
    #define MUSICAL_API __attribute__((visibility("default")))
#endif

extern "C" {

MUSICAL_API char* byWriteScales_C(int amount);

MUSICAL_API char* byRecognizeIntervalsGrades_C(int amount);

MUSICAL_API char* byRecognizeIntervalsNotes_C(
    int amount,
    int OctMin,
    int OctMax
);

MUSICAL_API char* byFormIntervals_C(
    int amount,
    int numElements
);

MUSICAL_API char* byFormAugmentedSixthChords_C(int amount);

MUSICAL_API void freeCharPointer(char* ptr);

}
