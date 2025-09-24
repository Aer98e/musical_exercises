#ifndef DATA_MUSIC_H
#define DATA_MUSIC_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>

namespace dtMusic
{
	class Nota_c
	{
		private:
			int alteration;
			const int pitchValue;
			std::string name;

		public:
			Nota_c(std::string name , int natural): name(name), pitchValue(natural), alteration(natural){}

			std::string getName() {return this -> name; }
			int getAlteration() {return this -> alteration; }
			int getPitchValue() {return this -> pitchValue; }

			void addAlteration(int newState){
				this -> alteration += newState;
				if (this -> alteration > 11){
					this -> alteration -= 12;
				}

				else if(this -> alteration<0){
					this -> alteration+=12;
				}
			}

			void show() {std::cout<<"Nota("<<name<<"), estado("<<alteration<<").\n"; }
	};

    extern std::vector<Nota_c> notesObjects;

    extern std::vector<std::string> noteNames;

    extern std::vector<std::string> gradeWName;
	
	extern std::vector<std::string> gradeAwName;

    extern std::vector<std::string> intervals;

	extern std::vector<std::string> scalesNameTypes;

	extern std::vector<std::string> directions;

	extern std::unordered_map<std::string, std::vector<int>> Patterns;

	extern std::map<int, int> valueIntervales;

	extern std::vector<std::string> typesAugmentChords;
}
#endif