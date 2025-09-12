#ifndef MUSIC_FUNTION_H
#define MUSIC_FUNTION_H

#include <string>
#include <vector>
#include <iostream>

int generate_rand_number(int max, int min = 0);

class Note{
    private:
        enum class grades {O, I, II, III, IV, V, VI, VII};

	    std::string name;
	    short valuePitch;
        short pitchVariation;
        grades grade;
	    Note* next;
        Note* previous;

    public:
        Note(std::string name, int natural, Note* next=nullptr, Note* previous=nullptr);

        std::string getName();

        short getValuePitch();

        std::string getGradeName();
        short getGradeValue();
        void changeGrade(int newValue);

        Note* getNextPtr();
        Note* getPreviousPtr();

        void modifyNextPtr(Note* newPtr);
        void modifyPreviousPtr(Note* newPtr);

        void setPitchVariation(short variation);
        short getPitchVariation();
        void resetPitchVariation();
        void show();
};

class Scale {
    private:
        static short size;
        static Scale* scaleBase;
        Note* selectedNote;
        void addNote(std::string name, int natural);
        Scale(); // Solo la declaración

    public:
        static Scale* getScale();
        void print();
        
        Note* randNote();
        std::vector<int> listPitchValues();

        short getSize();
        Note* getSelectedNote();

        void reassignGrades(short value);
        void selectNextNote(int steps = 1);
        void selectPreviousNote(int steps = 1);

        void applyScalePattern(std::vector<int> pattern, int initialModification = 0);
        void resetPitchVariations();
};

std::vector <int> addPattern(int init, std::vector<int> pattern);

std::pair<std::vector <int>, bool> alterations(std::vector<int> escala, std::vector<int> natural);

std::pair<std::string, std::vector<int>> getRandPattern();

#endif