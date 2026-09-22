#include "exercises_functions.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <utility>

using std::cout;
using std::endl;
using std::cin;

void printMenu (){
	cout << "\t====EJERCICIOS DE TEORIA MUSICAL====\n\n";
	cout << "1) Ejercicios para escalas.\n";
	cout << "2) Ejercicios de intervalos(GRADOS).\n";
	cout << "3) Ejercicios de intervalos(NOTAS).\n";
	cout << "4) Ejercicios para reconocer escalas.\n";
	cout << "5) Ejercicios para reconocer intervalos.\n";
	cout << "6) Ejercicios para sexta aumentada.\n\n";
}

std::pair<short, short> getOptions(){
	short selectOption {};

	cout << "Que ejercicio desea?: ";
	cin >> selectOption;
	// if(std::cin.fail)			IMPLEMENTAR ESTO
	cin.ignore(10, '\n');

	short amountExercises {};

	cout << "Cuantos ejercicios solicita?: ";
	cin >> amountExercises;
	cin.ignore(10, '\n');

	cout << "\n";
	return {selectOption, amountExercises};
}

short requestAmountElements()
{
	short amountElements {};
	
	cout<<"Cuantos elementos necesita: ";
	cin >> amountElements;
	cin.ignore(10, '\n');
	
	cout<<"\n";
	return amountElements;
}

int main(){
	Scale* nova = Scale::getScale();
	bool repeat = false;
	
	do{
		//system("clear");
		cout << "\033[2J\033[H";
		
		printMenu();
		auto [selectOption, amountExercises] = getOptions();
		
		switch(selectOption){
			case 1:
				byWriteScales_Nova(amountExercises, nova);
				break;
			
			case 2:
				byRecognizeIntervalsGrades_Nova(amountExercises, nova);
				break;
			
			case 3:
				byRecognizeIntervalsNotes_Nova(amountExercises, nova);
				break;

			case 4: { 
				short amountElements {requestAmountElements()};
				byRecognizeScale(amountExercises, amountElements);
				break;
			}

			case 5: {
				short amountElements {requestAmountElements()};
				byFormIntervals(amountExercises, amountElements);
				break;
			}

			case 6: 
				byFormAugmentedSixthChords(amountExercises, nova);
				break;

			default:
				//system("clear");
				cout << "\033[2J\033[H";
				cout <<"\a\n\tError de solicitud.\n Vuelve a intentarlo.\n" <<std::endl;
		}
		cout <<"\nDesea volver a iniciar?(1 = si || 0 = no): ";
		cin >>repeat;
		cin.ignore(10, '\n');
		
	}while(repeat);
}