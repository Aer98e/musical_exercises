#pragma once
#include <string>

enum class grades { O, I, II, III, IV, V, VI, VII };

class Note {
public:
    Note(std::string name, int natural, Note* next = nullptr, Note* previous = nullptr);
    
    std::string getName();

    std::string getGradeName();
    short getGradeValue();
    void changeGrade(int value);
    
    Note* getNextPtr();
    Note* getPreviousPtr();
    void modifyNextPtr(Note* newPtr);
    void modifyPreviousPtr(Note* newPtr);
    
    short getValuePitch();
    void setPitchVariation(short variation);
    short getPitchVariation();
    void resetPitchVariation();
    int getGeneralPitch();
    
    void show();
private:
    std::string name;
    int valuePitch;
    Note* next;
    Note* previous;
    short pitchVariation;
    grades grade;
};