#include "scale.h"
#include <iostream>
#include <stdexcept>
#include "note.h"
#include "music_utils.h"

Scale* Scale::scaleBase = nullptr;
short Scale::size {0};

Scale::Scale() : selectedNote(nullptr) {
    addNote("Do", 0);
    addNote("Re", 2);
    addNote("Mi", 4);
    addNote("Fa", 5);
    addNote("Sol", 7);
    addNote("La", 9);
    addNote("Si", 11);
    reassignGrades(1);
}

Scale* Scale::getScale() {
    if (scaleBase == nullptr) {
        scaleBase = new Scale();
    }
    return scaleBase;
}

void Scale::selectNextNote(int steps) {
    for (int i = 0; i < steps; i++) {
        selectedNote = selectedNote->getNextPtr();
    }
}

void Scale::selectPreviousNote(int steps) {
    for (int i = 0; i < steps; i++) {
        selectedNote = selectedNote->getPreviousPtr();
    }
}

Note* Scale::getSelectedNote() { return selectedNote; }

void Scale::reassignGrades(short value) {
    short gradeValue {value};
    Note* temp = selectedNote;
    for (int i = 0; i < this->size; i++) {
        if (gradeValue > 7) { gradeValue -= 7; }
        temp->changeGrade(gradeValue);
        temp = temp->getNextPtr();
        gradeValue += 1;
    }
}

void Scale::addNote(std::string name, int natural) {
    Note* new_note = new Note(name, natural);

    if (selectedNote == nullptr) {
        selectedNote = new_note;
        selectedNote->modifyNextPtr(selectedNote);
        selectedNote->modifyPreviousPtr(selectedNote);
    } else {
        Note* temp = selectedNote;
        while (temp->getNextPtr() != selectedNote) {
            temp = temp->getNextPtr();
        }
        temp->modifyNextPtr(new_note);
        new_note->modifyPreviousPtr(temp);
        new_note->modifyNextPtr(selectedNote);
        selectedNote->modifyPreviousPtr(new_note);
    }
    Scale::size++;
}

short Scale::getSize() { return size; }

void Scale::applyScalePattern(std::vector<int> pattern, int initialModification) {
    if (pattern.size() != size) {
        throw std::invalid_argument("El tamaño del patrón no es aplicable en la escala.");
    }
    int verification = 0;
    for (int step : pattern) { verification += step; }
    if (verification != 12) { throw std::invalid_argument("La suma del patrón debe ser 12."); }

    if (initialModification * initialModification > 1) {
        throw std::invalid_argument("El valor para 'initialModification' debe estar entre -1 y 1.");
    }

    reassignGrades(1);

    std::vector<int> firstApply {};
    firstApply.push_back(selectedNote->getValuePitch() + initialModification);

    for (int step : pattern) {
        firstApply.push_back(firstApply.back() + step);
    }

    Note* temp = selectedNote;
    for (int value : firstApply) {
        int secondApply {value - temp->getValuePitch()};
        if (secondApply > 2) { secondApply -= 12; }
        temp->setPitchVariation((short)secondApply);
        temp = temp->getNextPtr();
    }
}

void Scale::resetPitchVariations() {
    for (int i = 0; i < size; i++) {
        selectedNote->resetPitchVariation();
        selectNextNote();
    }
}

void Scale::print() {
    Note* temp = selectedNote;
    while (temp->getGradeValue() != 1) {
        temp = temp->getNextPtr();
    }
    for (int i = 0; i < size; i++) {
        std::cout << temp->getName() << "("
                  << temp->getGradeName() << ")" << " - ";
        temp = temp->getNextPtr();
    }
    std::cout << "\n";
}

std::vector<int> Scale::listPitchValues() {
    std::vector<int> numbers;
    Note* temp = selectedNote;
    for (int i = 0; i < size; i++) {
        numbers.push_back(temp->getValuePitch());
        temp = temp->getNextPtr();
    }
    return numbers;
}

Note* Scale::randNote() {
    int limit = generate_rand_number(size - 1);
    Note* temp = selectedNote;
    for (int i = 0; i < limit; i++) {
        temp = temp->getNextPtr();
    }
    selectedNote = temp;
    return temp;
}