#include "exercises_funtions.h"
#include "data_music.h"
#include "music_funtion.h"

#include <iostream>
#include <vector>
#include <string>


int generate_rand_number(int max, int min);

void byWriteScales(int amount){
	struct select {
		int note {};
		int grade {};
		int scale {};
		int direction {};
	};
	
	select sel;

	for(amount; amount > 0; amount--){
			sel.note = generate_rand_number(dtMusic::noteNames.size()-1);
			sel.grade = generate_rand_number(dtMusic::gradeAwName.size()-1);
			sel.scale = generate_rand_number(dtMusic::scalesNameTypes.size()-1);
			sel.direction = generate_rand_number(dtMusic::directions.size()-1);

			std::cout << "Escribe una escala " << dtMusic::scalesNameTypes[sel.scale];
			std::cout << " " << dtMusic::directions[sel.direction];
			std::cout << " con " << dtMusic::noteNames[sel.note] << " como ";
			std::cout << dtMusic::gradeAwName[sel.grade] << "\n";
	}

}

void byWriteScales_Nova(int amount, Scale* nova){
	int direction {};

	for(amount; amount > 0; amount--){
			nova -> randNote();
			auto[scaleName, scalePattern] = getRandPattern();
			int variation { generate_rand_number(1, -1) };
			nova -> applyScalePattern(scalePattern, variation);
			nova -> randNote();
			Note* temp = nova -> getSelectedNote();

			direction = generate_rand_number(dtMusic::directions.size()-1);

			std::cout << "Escribe una escala " << scaleName;
			std::cout << " " << dtMusic::directions[direction];
			std::cout << " con "<<temp -> getName()<< " como ";
			std::cout << temp->getGradeName() << "\n";

			// nova->print();
	}

}

void byRecognizeIntervalsGrades_Nova(int amount, Scale* nova){
	int selectGrade = {};
	int sizeGradeVector = dtMusic::gradeAwName.size();

	for(amount; amount > 0; amount--){
			auto[scaleName, scalePattern] = getRandPattern();
			nova -> applyScalePattern(scalePattern);
			nova -> randNote();
			Note* firtNote = nova -> getSelectedNote();
			nova -> randNote();
			Note* secondNote = nova -> getSelectedNote();

			std::cout <<"Dada la escala " <<scaleName
			<<" mensiona el intervalo entre los grados "
			<<firtNote -> getGradeName() <<" y " <<secondNote -> getGradeName()
			<<"\n";
			
	}
	
}

void byRecognizeIntervals_Notes(int amount, int octaveMin, int octaveMax){
	int selectNote {};
	int selecOctave {};
	int sizeNotesList  (dtMusic::noteNames.size());

	for(amount; amount > 0; amount--){
			selectNote = generate_rand_number(sizeNotesList-1);
			selecOctave = generate_rand_number (octaveMax, octaveMin);

			std::cout << "Intervalo entre "<< dtMusic::noteNames[selectNote] <<" "<< selecOctave;
			
			selectNote = generate_rand_number(sizeNotesList-1);
			selecOctave=generate_rand_number(octaveMax, octaveMin);
			
			std::cout << " y "<< dtMusic::noteNames[selectNote] << " "<< selecOctave << "\n";
	}
	
}

void byRecognizeScale(int amount, int numElements){
	int selectNote {};
	int counter {numElements};
	int sizeNotesList (dtMusic::noteNames.size());
	
	for(amount; amount > 0; amount--){
		selectNote = generate_rand_number(sizeNotesList-1);

		std::cout << "Que escala contiene " << dtMusic::noteNames[selectNote];

		for(counter; counter > 1; counter--){
			selectNote = generate_rand_number(sizeNotesList-1);

			std::cout << ", " << dtMusic::noteNames[selectNote];
		}

		counter = numElements;
		std::cout << "\n";
	}
}

void byFormIntervals(int amount, int numElements){
	int selectNote {};
	int sizeNotesList (dtMusic::noteNames.size());
	int selectInterval {};
	int sizeIntervalsList (dtMusic::intervals.size());
	int counter {numElements};
	
	for(amount; amount > 0; amount--){
		selectNote = generate_rand_number(sizeNotesList-1);
		selectInterval = generate_rand_number(sizeIntervalsList-1);

		std::cout << "Con " << dtMusic::noteNames[selectNote] << " forma: " << dtMusic::intervals[selectInterval];
		
		for(counter; counter > 1; counter--){
			selectInterval = generate_rand_number(sizeIntervalsList-1);
			std::cout<< ", " <<dtMusic::intervals[selectInterval];
		}

		counter = numElements;
		std::cout<<"\n";
	}
}