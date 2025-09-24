#include "data_music.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <map>

namespace dtMusic
{
    std::vector<Nota_c> notesObjects = {
                            Nota_c{"Do", 0},
                            Nota_c{"Re", 2},
                            Nota_c{"Mi", 4},
                            Nota_c{"Fa", 5},
                            Nota_c{"Sol", 7},
                            Nota_c{"La", 9},
                            Nota_c{"Si", 11}
                        };

    std::vector<std::string> noteNames = {
                            "Do", "Re", "Mi", "Fa", "Sol", "La", "Si",
                            "Do#", "Re#", "Mi#", "Fa#", "Sol#", "La#", "Si#",
                            "Dob", "Reb", "Mib", "Fab", "Solb", "Lab", "Sib"
                        };

    std::vector<std::string> gradeWName = {
                            "Tónica",
                            "Supertónica",
                            "Mediante",
                            "Subdominante",
                            "Dominante",
                            "Submediante",
                            "Sensible"
                        };
	
	std::vector<std::string> gradeAwName = {"I", "II", "III", "IV", "V", "VI", "VII"};

    std::vector<std::string> intervals = {
                        "Segunda mayor", "Segunda menor",    //"Segunda aumentada", "Segunda disminuida", 
			            "Tercera mayor", "Tercera menor",    //"Tercera aumentada", "Tercera disminuida", 
			            "Cuarta justa",  "Cuarta aumentada", //"Cuarta disminuida", 
			            "Quinta justa",                      "Quinta disminuida", 
			            "Sexta mayor",   "Sexta menor",      "Sexta aumentada",    //"Sexta disminuida",
			            "Septima mayor", "Septima menor",    //"Septima aumentada",  "Septima disminuida",
			            "Octava justa",  //"Octava aumentada", "Octava disminuida"
                    };

    std::vector<std::string> scalesNameTypes = {
                        "Mayor",
                        "Menor Natural",
                        "Menor Armonica",
                        "Menor Melodica",
    };

    std::vector<std::string> directions = {"Ascendente", "Descendente"};

    std::unordered_map<std::string, std::vector<int>> Patterns{
        {"Mayor", {2, 2, 1, 2, 2, 2, 1}},
        {"Menor Natural", {2, 1, 2, 2, 1, 2, 2}},
        {"Menor Armonica", {2, 1, 2, 2, 1, 3, 1}},
        {"Menor Melodica", {2, 1, 2, 2, 2, 2, 1}},
    };

    std::map<int, int> valueIntervales {
	{1, 1}, {2, 2},	{3, 4},
	{4, 5},	{5, 7},	{6, 9},
	{7, 11}, {8, 12}
    }; 

    std::vector<std::string> typesAugmentChords {
        "Alemena", "Italiana", "Suiza", "Francesa"
    };
}