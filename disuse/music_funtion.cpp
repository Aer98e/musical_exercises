#include "music_funtion.h"
#include "data_music.h"

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include <stdexcept>

int generate_rand_number(int max, int min);

Note::Note(std::string name, int natural, Note* next, Note* previous)
	:name(name), valuePitch(natural), next(next), previous(previous),
	pitchVariation(0), grade(grades::O){}

std::string Note::getName(){
	std::string specificName {name};
	int tempPitch = pitchVariation;
	
	while (tempPitch!=0){
		if (tempPitch < 0){
			specificName += "b";
			tempPitch += 1;
			continue;
		}
		specificName += "#";
		tempPitch -= 1;
	}
	return specificName;
}

std::string Note::getGradeName(){
	switch (grade)
	{
	case grades::I : return "I";
	case grades::II : return "II";
	case grades::III : return "III";
	case grades::IV : return "IV";
	case grades::V : return "V";
	case grades::VI : return "VI";
	case grades::VII : return "VII";
	
	default:
		return "None";
	}
}

short Note::getGradeValue(){ return static_cast<int> (grade); }

void Note::changeGrade(int value){
	if (!(value <=7) && !(value>=1)){
		throw std::invalid_argument("Solo se admiten valores entre 1 y 7.");
	}
	grade = static_cast<grades> (value);
}

Note* Note::getNextPtr(){ return next; }
Note* Note::getPreviousPtr(){ return previous; }

void Note::modifyNextPtr(Note* newPtr){ next = newPtr; }
void Note::modifyPreviousPtr(Note* newPtr){ previous = newPtr; }

short Note::getValuePitch(){ return valuePitch; }
void Note::setPitchVariation(short variation){ pitchVariation = variation; }
short Note::getPitchVariation(){ return pitchVariation; }
void Note::resetPitchVariation(){ pitchVariation = 0; }
int Note::getGeneralPitch(){ return pitchVariation + valuePitch; }

void Note::show(){
	std::cout<<"Note (name):"<<name
	<<" ,(valuePitch):"<<valuePitch
	<<" ,(next):"<<next<<"\n";
}

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
	for (int i=0; i<steps; i++){
		selectedNote = selectedNote -> getNextPtr();
	}
}
void Scale::selectPreviousNote(int steps){
	for (int i=0; i<steps; i++){
		selectedNote = selectedNote -> getPreviousPtr();
	}
}

Note* Scale::getSelectedNote() { return selectedNote; }

void Scale::reassignGrades(short value){
	short gradeValue {value};
	Note* temp = selectedNote;
	for(int i=0; i < this->size; i++){
		if (gradeValue > 7){ gradeValue -= 7; }
		temp -> changeGrade(gradeValue);
		temp = temp -> getNextPtr();
		gradeValue += 1;
	}
}

void Scale::addNote(std::string name, int natural){
	Note* new_note = new Note(name, natural);

	if (selectedNote == nullptr){
		selectedNote = new_note; 
		selectedNote -> modifyNextPtr(selectedNote);
		selectedNote -> modifyPreviousPtr(selectedNote);
	}

	else{
		Note* temp = selectedNote;

		while(temp -> getNextPtr() != selectedNote){
			temp = temp -> getNextPtr();
		}
		temp -> modifyNextPtr(new_note);
		new_note -> modifyPreviousPtr(temp);
		new_note -> modifyNextPtr(selectedNote);
		selectedNote -> modifyPreviousPtr(new_note);
	}

	Scale::size++;
}

short Scale::getSize(){ return size; }

void Scale::applyScalePattern(std::vector<int> pattern, int initialModification){
	if (pattern.size()!=size){
		throw std::invalid_argument("El tamaño del patrón no es aplicable en la escala.");
	}
	
	int* verification = new int(0);//No es necesaria la memoria dinamica, pero para probar.
	for (int step:pattern){ *verification += step; }
	if (*verification != 12){ throw std::invalid_argument("La suma del patrón debe ser 12."); }
	delete verification;
	verification = nullptr;

	if (initialModification * initialModification > 1){
		throw std::invalid_argument("El valor para 'initialModification' debe estar entre -1 y 1.");
	}

	reassignGrades(1);

	std::vector<int> firstApply {};
	
	firstApply.push_back(selectedNote->getValuePitch() + initialModification);
	
	for (int step : pattern){
		firstApply.push_back(firstApply.back() + step);
	}

	Note* temp = selectedNote;
	for (int value:firstApply){
		int secondApply {value - temp->getValuePitch()};
		if (secondApply > 2){ secondApply-=12; }
		temp -> setPitchVariation((short)secondApply);
		temp = temp -> getNextPtr();
	}
}

void Scale::resetPitchVariations(){
	for(int i=0; i<size; i++){
		selectedNote -> resetPitchVariation();
		selectNextNote();
	}
}

void Scale::print(){
	Note* temp = selectedNote;
	while(temp -> getGradeValue() != 1){
		temp = temp -> getNextPtr();
	}
	for(int i=0; i<size; i++){
		std::cout << temp -> getName() << "("
		<< temp -> getGradeName() <<")"<<" - ";
		temp = temp -> getNextPtr();
	}
	std::cout<<"\n";
}

std::vector<int> Scale::listPitchValues(){
    // Dado un objeto Note de una lsita circular, recorre toda la lsita y devuelve
    // un vector con los valores de altura de cada nota.
	std::vector<int> numbers;
	Note* temp = selectedNote;
	
	for (int i = 0; i < size; i++){
		numbers.push_back(temp -> getValuePitch());
		temp = temp->getNextPtr();
	}
	
	return numbers;
}

Note* Scale::randNote(){
    // Dada una lista circualr de objetos Note devuelve un puntero a uno de sus elementos aleatoriamente.
	int limit = generate_rand_number(size-1);
	Note* temp = selectedNote;
	
	for (int i = 0; i < limit; i++){
		temp = temp -> getNextPtr();
	}
	selectedNote = temp;
	return temp;
}


std::pair<std::string, std::vector<int>> getRandPattern(){
	int sizePattern { dtMusic::Patterns.size() };
	int randSelect { generate_rand_number(sizePattern-1) };
	auto iter { dtMusic::Patterns.begin()} ; 
	std::advance(iter, randSelect);
	return {iter -> first, iter -> second};
}

// Constructor
specificIntervalName::specificIntervalName(std::string name,
                                           specificIntervalName* up,
                                           specificIntervalName* down)
    : name(std::move(name)), up(up), down(down) {}

// Getters
std::string specificIntervalName::getName() const {
    return name;
}

specificIntervalName* specificIntervalName::getUp() const {
    return up;
}

specificIntervalName* specificIntervalName::getDown() const {
    return down;
}

// Setters
void specificIntervalName::setUp(specificIntervalName* newUp) {
    up = newUp;
}

void specificIntervalName::setDown(specificIntervalName* newDown) {
    down = newDown;
}

// Constructor
IntervalNetwork::IntervalNetwork()
    : major("Mayor"),
      minor("Menor"),
      just("Justo"),
      augmented("Aumentado"),
      disminished("Disminuido"),
      intervalSelected(nullptr)
{
    // Relaciones básicas entre intervalos
    major.setUp(&augmented);
    major.setDown(&minor);

    minor.setUp(&major);
    minor.setDown(&disminished);

    just.setDown(&disminished);
    just.setUp(&augmented);
}

// Singleton
IntervalNetwork& IntervalNetwork::getInstance() {
    static IntervalNetwork instance;
    return instance;
}

// Selección de modo
void IntervalNetwork::selectMode(Mode mode) {
    switch (mode) {
        case Mode::Mayor:
            intervalSelected = &major;
            disminished.setUp(&minor);
            augmented.setDown(&major);
            break;

        case Mode::Justo:
            intervalSelected = &just;
            disminished.setUp(&just);
            augmented.setDown(&just);
            break;
    }
}

// Navegar hacia arriba
void IntervalNetwork::up() {
    auto temp = intervalSelected->getUp();
    if (!temp) throw std::runtime_error("No existe intervalo más alto.");
    intervalSelected = temp;
}

// Navegar hacia abajo
void IntervalNetwork::down() {
    auto temp = intervalSelected->getDown();
    if (!temp) throw std::runtime_error("No existe intervalo más bajo.");
    intervalSelected = temp;
}

// Calcular intervalo
std::string IntervalNetwork::calculateInterval(int desviation) {
    if (intervalSelected == nullptr) {
        throw std::runtime_error("No se ha seleccionado ningún modo.");
    }

    while (desviation != 0) {
        if (desviation < 0) {
            down();
            desviation += 1;
        } else {
            up();
            desviation -= 1;
        }
    }

    return intervalSelected->getName();
}


// struct GenerateScale{
// 	std::vector <int> addPattern(int init, std::vector<int> pattern){
// 		// Dada un pitchValue, sigue un patron para generar una vector para una escala.
// 		std::vector <int> result;
// 		result.push_back(init);

// 		for (int i = 0; i < pattern.size(); i++){
// 			result.push_back(result.back() + pattern[i]);
// 		}
// 		return result;
// 	}

// 	std::pair<std::vector <int>, bool> normalizeAlterations(std::vector<int> alteredValues, std::vector<int> naturalValues){
// 		std::vector <int> normalizedValues;

// 		if (alteredValues.size() != naturalValues.size()){
// 			throw std::invalid_argument("Las listas no tienen la misma cantidad de elementos.");
// 		}

// 		for (int i = 0; i < alteredValues.size(); i++){
// 			int normalizeValue = alteredValues[i] - naturalValues[i];
		
// 			if(abs(normalizeValue) > 2){
// 				normalizeValue -= 12;
// 			}
		
// 			if(abs(normalizeValue) == 2){
// 				return {normalizedValues, false};
// 			}	
// 			//REVISAR LA LOGICA PARA ESCRIBIRLA
// 			normalizedValues.push_back(normalizeValue);
// 		}
		
// 		return {normalizedValues, true};
// 	}

// 	void selectValidNote(Note* someElement, std::vector<int> pattern, bool simpleAlteration = true)
// 	{
// 		int seedAlteration {simpleAlteration ? 1 : 2};

// 		Note* selectNote;
// 		std::pair<std::vector <int>, bool> normalizedAlterations;

// 		while (true)
// 		{
// 			selectNote = randNote(someElement);

// 			std::vector <int> pitchNaturalValues = listPitchValues(selectNote);
// 			int alteration = generate_rand_number(seedAlteration, seedAlteration*-1);

// 			std::vector <int> pitchAltererValues = addPattern(pitchNaturalValues[0] + alteration, pattern);
// 			normalizedAlterations = normalizeAlterations(pitchAltererValues, pitchNaturalValues);
// 			if (normalizedAlterations.second)
// 			{
// 				break;
// 			}
// 		}
// 	}
// };

