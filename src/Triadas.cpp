#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define PNOTE 0
#define PSIGNED 1
#define PDUPLICADO 2

using namespace std;

void SelectRandNT(int Papelera[][3]);
void SelecSignedNTR(int Papelera[][3], int FormaTriada[][2], int ValorSigno[]);
void PrintPapeleraNTR(int Papelera[][3], string Notas[]);

int main(){
	srand(time(NULL));
	//NOMBRE & NUMERO DE NOTAS GENERALES ESTATICAS
	string NoteNames[7] = {"Do", "Re", "Mi", "Fa", "Sol", "La", "Si"};
	int NoteSigned[7] = {0, 2, 4, 5, 7, 9, 11};
	int TipeTriad[8][2] = {{4,3},{3,4},{4,3},{3,4},{4,3},{3,4},{3,3},{4,4}};
	
	int PapeleraTriada[3][3];
	int NumPedido;
	
	cout<<"Numero de ejercicios: ";
	cin>>NumPedido;
	
	for(int i = 0; i < NumPedido; i++){
		SelectRandNT(PapeleraTriada);
		SelecSignedNTR(PapeleraTriada, TipeTriad, NoteSigned);
		PrintPapeleraNTR(PapeleraTriada,NoteNames);
	}
	
	system("PAUSE");
	return 0;
}	


void SelectRandNT(int Papelera[][3]){
	Papelera[PNOTE][0] = rand()%7;
	
	Papelera[PNOTE][1]=Papelera[PNOTE][0]+2;
	if(Papelera[PNOTE][1]>6){
		Papelera[PNOTE][1]-=7;
	}
	
	Papelera[PNOTE][2]=Papelera[PNOTE][1]+2;
	if(Papelera[PNOTE][2]>6){
		Papelera[PNOTE][2]-=7;
	}
}

void SelecSignedNTR(int Papelera[][3],int FormaTriada[][2], int ValorSigno[]){
	int NumRand;
	
	Papelera[PSIGNED][0]=ValorSigno[Papelera[PNOTE][0]];
	NumRand = rand()%3-1;
	Papelera[PSIGNED][0]+=NumRand;
	
	NumRand = rand()%8;
	for(int i=0;i<2;i++){
		Papelera[PSIGNED][i+1]=Papelera[PSIGNED][i]+FormaTriada[NumRand][i];
		if(Papelera[PSIGNED][i+1]>12){
			Papelera[PSIGNED][i+1]-=12;
		}
	}
	//Simplificacion de Valor para Signo
	for(int i=0;i<3;i++){
		Papelera[PSIGNED][i]-=ValorSigno[Papelera[PNOTE][i]];
		if(Papelera[PSIGNED][i]>2){
			Papelera[PSIGNED][i]-=12;
		}
		if(Papelera[PSIGNED][i]<-2){
			Papelera[PSIGNED][i]+=12;
		}
	}
	
}

void PrintPapeleraNTR(int Papelera[][3], string Notas[]){
	int NumRand;
	bool Rectificador=1;
	//Inicializa los espacios.
	for(int i=0;i<3;i++){
		Papelera[PDUPLICADO][i]=1;
	}
	//Escoge el Duplicado
	NumRand=rand()%3;
	Papelera[PDUPLICADO][NumRand]+=1;
	
	//Escritir de Signos
	while(Rectificador){
		NumRand=rand()%3;
		if(Papelera[PDUPLICADO][NumRand]!=0){
			cout<<Notas[Papelera[PNOTE][NumRand]];
			switch (Papelera[PSIGNED][NumRand]){
				case 1:
					cout<<"#";
					break;
				case 2:
					cout<<"X";
					break;
				case -1:
					cout<<"b";
					break;
				case -2:
					cout<<"bb";
					break;					
			}
			cout<<"("<<rand()%4+2<<")"<<" //  ";
			Papelera[PDUPLICADO][NumRand]--;
		}
		Rectificador=0;
		for(int i=0;i<3;i++){
			if(Papelera[PDUPLICADO][i]!=0){
				Rectificador=1;
			}
		}
		
	}
	cout<<"\n";
}
