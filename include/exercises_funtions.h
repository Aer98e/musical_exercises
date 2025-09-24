#pragma once
#include "scale.h"
#include "note.h"


void byFormIntervals(int amount, int numElements);
void byRecognizeScale(int amount, int numElements);
void byRecognizeIntervals_Notes(int amount, int octaveMin=2, int octaveMax=7);
void byRecognizeIntervalsNotes_Nova(int amount, Scale* nova, int octaveMin=2, int octaveMax=7);
// void byRecognizeIntervals_Grades(int amount);
void byRecognizeIntervalsGrades_Nova(int amount, Scale* nova);
void byWriteScales(int amount);
void byWriteScales_Nova(int amount, Scale* nova);
void byFormAugmentedSixthChords(int amount, Scale* nova);