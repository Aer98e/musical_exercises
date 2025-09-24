#include <iostream>
#include <random>
#include <vector>
// #include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

void ImprEjcEscEscl(int);
void ImprEjcGr(int);
void ImprEjcNt(int);
void ImprEjcReEsc(int, int);
void ImprEjcReIntvG(int, int);
int generate_rand_number(int max, int min=0);

struct Note{
	string name;
	const int natural;
	Note* next;
	Note(string name, const int natural):name(name), natural(natural), next(nullptr){}
};

void addNote(Note*& head, string name, int natural){
	Note* new_note = new Note(name, natural);

	if (!head){
		head = new_note;
		head -> next=head;
	}
	else{
		Note* temp = head;
		while(temp -> next != head){
			temp = temp -> next;
		}
		temp -> next = new_note;
		new_note -> next = head;
	}
}

int sizeListNote(Note*& head){
	int contador=1;
	Note* temp = head;
	
	while (temp->next!=head){
		contador+=1;
		temp = temp->next;
	}
	
	return contador;
}

vector<int> listNaturalInt(Note*& init){
	vector<int> numbers;
	Note* temp = init;
	
	for (int i = 0; i < sizeListNote (init); i++){
		numbers.push_back(temp->natural);
		temp = temp->next;
	}
	
	return numbers;
}

Note* randNote(Note*& head){
	int limit = generate_rand_number(sizeListNote(head)+1);
	Note* temp = head;
	
	for (int i=0; i<limit+1;i++){
		temp = temp->next;
	}
	
	// cout<<"Nota escogida :"<<temp->name;
	return temp;
}

vector <int> addPattern(int init, vector<int> patron){
	vector <int> result;
	result.push_back(init);
	for (int i=0;i<patron.size();i++){
		result.push_back(result.back()+patron[i]);
	}
	return result;
}

pair<vector <int>, bool> alterations(vector<int> escala, vector<int> natural){
	vector <int> result;

	if (escala.size()!= natural.size()){
		cout<<"ERROR CRITICO, NO SON COMPATIBLES LOS PARAMETROS"<<endl;
		return {result, false};
	}
	for (int i=0;i<escala.size();i++){
		int revise = escala[i]-natural[i];
		if(abs(revise)>2){
			revise-=12;
		}
		if(abs(revise)==2){
			return {result, false};
		}	
		result.push_back(revise);
	}
	return {result, true};
}


class Nota_c{
	private:
		int state;
		const int natural;

	public:
		string name;
		Nota_c(string name , int natural):name(name), natural(natural), state(natural){}

		void addState(int newState){
			state += newState;
			if (state > 11){
				state -= 12;
			}

			else if(state<0){
				state+=12;
			}
		}

		void show()const{
			cout<<"Nota("<<name<<"), estado("<<state<<")."<<endl;
		}

		int getState( )const { return state; }
};

vector<Nota_c> Notas = {Nota_c{"Do", 0}, Nota_c{"Re", 2}, Nota_c{"Mi", 4},
					Nota_c{"Fa", 5}, Nota_c{"Sol", 7}, Nota_c{"La", 9},
				Nota_c{"Si", 11}};

vector<string> Nota = {"DO", "RE", "MI", "FA", "SOL", "LA", "SI"
	, "DO#", "RE#", "MI#", "FA#", "SOL#", "LA#", "SI#"
	, "DOb", "REb", "MIb", "Fab", "SOLb", "LAb", "SIb"};

vector<string> Grado = {"Tonica(I)", "Supertonica(II)","Mediante(III)",
	"Subdominante(IV)","Dominante(V)","Submediante(VI)","Sensible/Subtonica(VII)"};

vector<string> Intervalo = {"Segunda mayor", "Segunda menor", "Segunda aumentada", "Segunda disminuida", 
			"Tercera mayor", "Tercera menor", "Tercera aumentada", "Tercera disminuida", 
			"Cuarta justa", "Cuarta aumentada", "Cuarta disminuida", 
			"Quinta justa", "Quinta aumentada", "Quinta disminuida", 
			"Sexta mayor", "Sexta menor", "Sexta aumentada", "Sexta disminuida", 
			"Octava justa", "Octava aumentada", "Octava disminuida"};



int main(){

	Note* list_notes=nullptr;

	addNote(list_notes, "Do", 0);
	addNote(list_notes, "Re", 2);
	addNote(list_notes, "Mi", 4);
	addNote(list_notes, "Fa", 5);
	addNote(list_notes, "Sol", 7);
	addNote(list_notes, "La", 9);
	addNote(list_notes, "Si", 11);

	vector <int> pattern_major = {2, 2, 1, 2, 2, 2};
	vector <int> pattern_minor = {2, 1, 2, 2, 1, 3};
	Note* selectNote;
	pair<vector <int>, bool> alter;

	while (true){
		selectNote = randNote(list_notes);
		vector <int> numbers = listNaturalInt(selectNote);
		int variation = generate_rand_number(2, -1);
		vector <int> numbers_procces = addPattern(numbers[0] + variation, pattern_minor);
		alter = alterations(numbers_procces, numbers);
		if (alter.second){
			break;
		}
	}
	vector <string> scalla;
	for (int alter:alter.first){
		string note_temp = selectNote-> name;
		switch (alter)
		{
		case -1:
			note_temp+="b";
			break;
		case 1:
			note_temp+="#";
			break;
		default:
			break;
		}
		scalla.push_back(note_temp);
		selectNote = selectNote->next;
	}
	scalla.push_back(scalla.front());

	for (string value:scalla){
		cout<<value<<" ";
	}
	
		



	// for(int i=0;i<60;i++){	
	// 	int number = generate_rand_number(Nota.size());
	// 	if (number==21){
	// 		cout<<"===========ERROR============="<<endl;
	// 		system("pause");
	// 	}
	// 	cout<<number<<endl;
	// }
	

	system("pause");
	
	short OpMenu = 0, NumPedido = 0, NumElementos = 0;
	bool Repetir = 0;
	
	do{
		system("cls");
		cout<<"\t====EJERCICIOS DE TEORIA MUSICAL====\n"<<endl;
		cout<<"1) Ejercicios para escalas.\n";
		cout<<"2) Ejercicios de intervalos(GRADOS).\n";
		cout<<"3) Ejercicios de intervalos(NOTAS).\n";
		cout<<"4) Ejercicios para reconocer escalas.\n";
		cout<<"5) Ejercicios para reconocer intervalos\n"<<endl;
		
		cout<<"Que ejercicio desea?: ";
		cin>>OpMenu;
		cout<<"Cuantos ejercicios solicita?: ";
		cin>>NumPedido;
		cout<<"\n";
		
		switch(OpMenu){
			case 1:
				ImprEjcEscEscl(NumPedido);
				break;
			case 2:
				ImprEjcGr(NumPedido);
				break;
			case 3:
				ImprEjcNt(NumPedido);
				break;
			case 4:
				cout<<"Cuantos elementos necesita: ";
				cin>>NumElementos;
				cout<<"\n";
				ImprEjcReEsc(NumPedido,NumElementos);
				break;
			case 5:
				cout<<"Cuantos elementos necesita: ";
				cin>>NumElementos;
				cout<<"\n";
				ImprEjcReIntvG(NumPedido,NumElementos);
				break;
			default:
				system("cls");
				cout<<"\a\n\tError de solicitud.\n Vuelve a intentarlo.\n"<<endl;
		}
		cout << "\nDesea otro ejercicio?(1 = si || 0 = no): ";
		cin>>Repetir;
	}while(Repetir);
}

int generate_rand_number(int max, int min){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distribucion(min, max-1);
	return distribucion(gen);

}


void ImprEjcEscEscl(int Cantidad){//Ejercicio para Escribir Escalas
	int SelectorNota=0, SelectorGrado=0;
	
	for(Cantidad;Cantidad>0;Cantidad--){
			SelectorNota=generate_rand_number(Nota.size());
			SelectorGrado=generate_rand_number(Grado.size());
			cout<<Nota[SelectorNota]<<" como "<<Grado[SelectorGrado]<<endl;
	}

}

void ImprEjcGr(int Cantidad){//Reconocer Intervalos entre Grados
	int SltGr=0;//Selector de Grado

	for(Cantidad;Cantidad>0;Cantidad--){
			SltGr=generate_rand_number(Grado.size());
			cout<<"Intervalo entre "<<Grado[SltGr];
			SltGr=generate_rand_number(Grado.size());
			cout<<" y "<< Grado[SltGr]<<endl;
	}
	
}

void ImprEjcNt(int Cantidad){//Reoconoce Intervalos entre Notas
	int SltNt=0, SltOct=0;//Selector de Nota

	for(Cantidad;Cantidad>0;Cantidad--){
			SltNt=generate_rand_number(Nota.size());
			SltOct=generate_rand_number(7,2);
			cout<<"Intervalo entre "<<Nota[SltNt]<<" "<<SltOct;
			SltNt=generate_rand_number(Nota.size());
			SltOct=generate_rand_number(7,2);
			cout<<" y "<< Nota[SltNt]<<" "<<SltOct<<endl;
	}
	
}

void ImprEjcReEsc(int Cantidad, int NumElementos){
	int SltNt=0, ReiniciaContador=NumElementos;
	
	for(Cantidad; Cantidad>0; Cantidad--){
		SltNt=generate_rand_number(Nota.size());;
		cout<<"Que escala contiene "<<Nota[SltNt];

		for(NumElementos;NumElementos>1;NumElementos--){
			SltNt=generate_rand_number(Nota.size());
			cout<<", "<<Nota[SltNt];
		}
		NumElementos=ReiniciaContador;
		cout<<endl;
	}
}

void ImprEjcReIntvG(int Cantidad, int NumElementos){
	int SltNt=0, SltIntv=0, ReiniciaContador=NumElementos;
	
	for(Cantidad; Cantidad>0; Cantidad--){
		SltNt=generate_rand_number(Nota.size());
		SltIntv=generate_rand_number(Intervalo.size());
		cout<<"Con "<<Nota[SltNt]<<" forma: "<<Intervalo[SltIntv];
		
		for(NumElementos;NumElementos>1;NumElementos--){
			SltIntv=generate_rand_number(Intervalo.size());
			cout<<", "<<Intervalo[SltIntv];
		}
		NumElementos=ReiniciaContador;
		cout<<endl;
	}
}



