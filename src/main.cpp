#include "exercises_funtions.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <utility>

void printMenu (){
	std::cout << "\t====EJERCICIOS DE TEORIA MUSICAL====\n\n";
	std::cout << "1) Ejercicios para escalas.\n";
	std::cout << "2) Ejercicios de intervalos(GRADOS).\n";
	std::cout << "3) Ejercicios de intervalos(NOTAS).\n";
	std::cout << "4) Ejercicios para reconocer escalas.\n";
	std::cout << "5) Ejercicios para reconocer intervalos.\n";
	std::cout << "6) Ejercicios para sexta aumentada.\n\n";
}

std::pair<short, short> getOptions(){
	std::cout << "Que ejercicio desea?: ";
	short selectOption {};
	std::cin >> selectOption;
	// if(std::cin.fail)			IMPLEMENTAR ESTO
	std::cin.ignore(10, '\n');

	std::cout << "Cuantos ejercicios solicita?: ";
	short amountExercises {};
	std::cin >> amountExercises;
	std::cin.ignore(10, '\n');

	std::cout << "\n";
	return {selectOption, amountExercises};
}

short requestAmountElements()
{
	std::cout<<"Cuantos elementos necesita: ";
	short amountElements {};
	std::cin >> amountElements;
	std::cin.ignore(10, '\n');
	std::cout<<"\n";
	return amountElements;
}

int main(){
	Scale* nova = Scale::getScale();
	bool Repetir = false;
	
	do{
		system("cls");
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
				system("cls");
				std::cout<<"\a\n\tError de solicitud.\n Vuelve a intentarlo.\n"<<std::endl;
		}
		std::cout << "\nDesea otro ejercicio?(1 = si || 0 = no): ";
		std::cin>>Repetir;
		std::cin.ignore(10, '\n');
	}while(Repetir);
}