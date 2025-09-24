#include "note.h"
#include <iostream>
#include <stdexcept>

Note::Note(std::string name, int natural, Note* next, Note* previous)
    : name(name), valuePitch(natural), next(next), previous(previous),
      pitchVariation(0), grade(grades::O) {}

std::string Note::getName() {
    std::string specificName {name};
    int tempPitch = pitchVariation;
    while (tempPitch != 0) {
        if (tempPitch < 0) {
            specificName += "b";
            tempPitch += 1;
            continue;
        }
        specificName += "#";
        tempPitch -= 1;
    }
    return specificName;
}

std::string Note::getGradeName() {
    switch (grade) {
        case grades::I: return "I";
        case grades::II: return "II";
        case grades::III: return "III";
        case grades::IV: return "IV";
        case grades::V: return "V";
        case grades::VI: return "VI";
        case grades::VII: return "VII";
        default: return "None";
    }
}

short Note::getGradeValue() { return static_cast<short>(grade); }

void Note::changeGrade(int value) {
    if (!(value <= 7) && !(value >= 1)) {
        throw std::invalid_argument("Solo se admiten valores entre 1 y 7.");
    }
    grade = static_cast<grades>(value);
}

Note* Note::getNextPtr() { return next; }
Note* Note::getPreviousPtr() { return previous; }
void Note::modifyNextPtr(Note* newPtr) { next = newPtr; }
void Note::modifyPreviousPtr(Note* newPtr) { previous = newPtr; }
short Note::getValuePitch() { return static_cast<short> (valuePitch); }
void Note::setPitchVariation(short variation) { pitchVariation = variation; }
short Note::getPitchVariation() { return pitchVariation; }
void Note::resetPitchVariation() { pitchVariation = 0; }
int Note::getGeneralPitch() { return pitchVariation + valuePitch; }
void Note::show() {
    std::cout << "Note (name):" << name
              << " ,(valuePitch):" << valuePitch
              << " ,(next):" << next << "\n";
}