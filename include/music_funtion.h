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

        std::string getGradeName();
        short getGradeValue();
        void changeGrade(int newValue);

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

class specificIntervalName {
private:
    std::string name;
    specificIntervalName* up;
    specificIntervalName* down;

public:
    // Constructor
    specificIntervalName(std::string name,
                         specificIntervalName* up = nullptr,
                         specificIntervalName* down = nullptr);

    // Getters
    std::string getName() const;
    specificIntervalName* getUp() const;
    specificIntervalName* getDown() const;

    // Setters
    void setUp(specificIntervalName* newUp);
    void setDown(specificIntervalName* newDown);
};

class IntervalNetwork {
private:
    // Objetos de intervalos
    specificIntervalName major;
    specificIntervalName minor;
    specificIntervalName just;
    specificIntervalName augmented;
    specificIntervalName disminished;

    // Estado actual
    specificIntervalName* intervalSelected;

    // Constructor privado (Singleton)
    IntervalNetwork();

    // Evitar copia y asignación
    IntervalNetwork(const IntervalNetwork&) = delete;
    IntervalNetwork& operator=(const IntervalNetwork&) = delete;

public:
    enum class Mode { Mayor, Justo };
    // Obtener la única instancia
    static IntervalNetwork& getInstance();

    // Selección de modo
    void selectMode(Mode mode);

    // Navegación
    void up();
    void down();

    // Cálculo
    std::string calculateInterval(int desviation);
};

std::vector <int> addPattern(int init, std::vector<int> pattern);

std::pair<std::vector <int>, bool> alterations(std::vector<int> escala, std::vector<int> natural);

std::pair<std::string, std::vector<int>> getRandPattern();

#endif