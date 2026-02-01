#pragma once
#include <string>
#include <vector>
#include "note.h"

class Scale {
public:
    Scale();
    static Scale* getScale();

    void selectNextNote(int steps = 1);
    void selectPreviousNote(int steps = 1);
    Note* getSelectedNote();
    void goBeginning();
    Note* getBeginning();
    
    void reassignGrades(short value);
    void addNote(std::string name, int natural);
    short getSize();
    void applyScalePattern(std::vector<int> pattern, int initialModification=0);
    void resetPitchVariations();
    void print();
    std::vector<int> listPitchValues();
    Note* randNote();
private:
    Note* selectedNote;
    static Scale* scaleBase;
    static short size;
};