// Headers del proyecto (necesarios para ejecutar la lógica de las funciones)
#include "scale.hpp"
#include "note.hpp"
#include "data_music.hpp"
#include "music_utils.hpp"
#include "interval_network.hpp"

// Librerías estándar que utilices en las funciones
#include <iostream>
#include <vector>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

Scale* nova = Scale::getScale();

std::string byWriteScales_Nova(int amount){
	int direction {};
	json results = json::array();

	for(; amount > 0; amount--){
		nova -> randNote();
		auto[scaleName, scalePattern] = getRandPattern();
		int variation { generate_rand_number(1, -1) };
		nova -> applyScalePattern(scalePattern, variation);
		nova -> randNote();
		Note* temp = nova -> getSelectedNote();

		direction = generate_rand_number(dtMusic::directions.size()-1);


		json item = {
            {"scaleName", scaleName},
            {"direction", dtMusic::directions[direction]},
            {"noteName", temp -> getName()},
            {"noteGrade", temp -> getGradeName()},
            {"scale", nova -> printScale()}
        };

        results.push_back(item);
	}
	return results.dump();
}

std::pair<int, std::string> compareIntervals(Note* first, Note* second){
	int generalName { (second->getGradeValue() - first->getGradeValue()) + 1};
	if (generalName < 2){ generalName+=7; }

	IntervalNetwork &net = IntervalNetwork::getInstance();
	switch (generalName) {
		case 4: case 5: case 8:
			net.selectMode(Mode::Justo);
			break;
		default:
			net.selectMode(Mode::Mayor);
	}

	int naturalValue = dtMusic::valueIntervales[generalName];
	// std::cout <<"Se seleccionó el grado " <<generalName
	// <<" con valor natural de " <<naturalValue <<'\n';

	int realValue = second->getGeneralPitch() - first->getGeneralPitch();
	if (realValue < 0) { realValue += 12; }
	// std::cout <<"El valor alto es: " <<second->getGeneralPitch() <<" y"
	// <<"el valor bajo es: " <<first->getGeneralPitch() <<"\n";

	// std::cout <<"El valor real es " <<realValue<<"\n";

	int desviation = realValue-naturalValue;
	if (desviation == -12) { desviation = 0; }

	std::string specificName = net.calculateInterval(desviation);
	

	return {generalName, specificName};
}

std::string byRecognizeIntervalsGrades_Nova(int amount){
	json results = json::array();

	for(; amount > 0; amount--){
			auto[scaleName, scalePattern] = getRandPattern();
			nova -> applyScalePattern(scalePattern);

			Note* firstNote = nova -> randNote();
			Note* secondNote = nova -> randNote();

			auto [generalName, specificName] = compareIntervals(firstNote, secondNote);
			json item = {
				{"scaleName", scaleName},
				{"firstGrade", firstNote -> getGradeName()},
				{"secondGrade", secondNote -> getGradeName()},
				{"ansGeneralName", generalName},
				{"ansSpecificName", specificName}
			};
			results.push_back(item);
	}
	return results.dump();
	
}

std::string byRecognizeIntervalsNotes_Nova(int amount, int octaveMin, int octaveMax){
	json results = json::array();

	for(; amount > 0; amount--){
		nova -> randNote();
		int variation { generate_rand_number(1, -1) };

		auto[scaleName, scalePattern] = getRandPattern();
		nova -> applyScalePattern(scalePattern, variation);

		Note* firstNote = nova -> randNote();
		Note* secondNote = nova -> randNote();
		
                int firstOctave = generate_rand_number(octaveMax, octaveMin);
                int secondOctave = generate_rand_number(octaveMax, octaveMin);
                std::pair<int, std::string> intervalAllName{};
                if (firstOctave < secondOctave){
                  intervalAllName = compareIntervals(firstNote, secondNote);
                }
                else{
                  intervalAllName = compareIntervals(secondNote, firstNote);
                }
		auto [generalName, specificName] = intervalAllName;
		json item = {
			{"firstNote", firstNote->getName()},
			{"secondNote", secondNote->getName()},
			{"firstOctave", firstOctave},
			{"secondOctave",  secondOctave},
			{"ansGeneralName", generalName},
			{"ansSpecificName", specificName}
		};

		results.push_back(item);
	}

	return results.dump();
}

void byRecognizeScale(int amount, int numElements){
	int selectNote {};
	int counter {numElements};
	int sizeNotesList {static_cast<int>(dtMusic::noteNames.size())};
	
	for(; amount > 0; amount--){
		selectNote = generate_rand_number(sizeNotesList-1);

		std::cout << "Que escala contiene " << dtMusic::noteNames[selectNote];

		for(; counter > 1; counter--){
			selectNote = generate_rand_number(sizeNotesList-1);

			std::cout << ", " << dtMusic::noteNames[selectNote];
		}

		counter = numElements;
		std::cout << "\n";
	}
}

std::string byFormIntervals(int amount, int numElements){
	int randIdxNote {};
	int sizeNotesList {static_cast<int>(dtMusic::noteNames.size())};
	int sizeIntervalsList { static_cast<int>( dtMusic::intervals.size() ) };
	int counter {numElements};
	
	json results = json::array();
	
	for(; amount > 0; amount--){
		randIdxNote = generate_rand_number(sizeNotesList-1);

		json intervals = json::array();
		
		for(; counter > 0; counter--){
			int randIdxInterval = generate_rand_number(sizeIntervalsList-1);
			intervals.push_back(dtMusic::intervals[randIdxInterval]);
		}

		json item = {
			{"noteName", dtMusic::noteNames[randIdxNote]},
			{"intervals", intervals}
		};

		results.push_back(item);
		counter = numElements;
	}
	return results.dump();
}

std::string byFormAugmentedSixthChords_Nova(int amount){
	json results = json::array();

	for (int i=0; i<amount; i++){
		nova -> randNote();
		Note* note = nova -> getSelectedNote();

		int alteration = generate_rand_number(0,-1);
		note -> setPitchVariation((short)alteration);

		int limit {(int)dtMusic::typesAugmentChords.size()};
		int selectChord = generate_rand_number(limit-1);

		json item = {
			{"typeChord", dtMusic::typesAugmentChords[selectChord]},
			{"noteName", note->getName()} 
		};

		results.push_back(item);
	}
	return results.dump();
}
