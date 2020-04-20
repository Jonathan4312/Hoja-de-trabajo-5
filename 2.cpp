/*EJERCICIO#2
Realice un programa que, dado el peso, la altura, la edad y el género (M/F) de un grupo de N personas
que pertenecen a un departamento de la república, obtenga un promedio de peso, altura y edad de esta
población. Los datos deben guardarse de forma ordenada por edad en un archivo de datos. Así mismo
el programa debe ser capaz leer los datos del archivo y generar un reporte con la media del peso, altura
y la edad. */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void ingresar();
void reporte();

int main(){
	ingresar();
	//reporte();
}

void ingresar(){
	int N;//numero de personas 
	float peso[N];
	float altura[N];
	int edad[N];
	char genero[10];
	float sumap=0;//suma de peso
	float sumaa=0;//suma de altura
	float sumae=0;//suma de edad
	float mpeso=0; //media de peso
	float maltura=0;//media de altura
	float medad=0;//media de edad
	string s;
	
	cout<<"Digite el numero de personas: ";
	cin>>N;
	
	for(int i=0;i<N;i++){
		fflush(stdin);
		cout<<"\n";
		cout<<"Peso de la persona en libras: "; cin>>peso[i];
		fflush(stdin);
		cout<<"Altura de la persona: "; cin>>altura[i];
		cout<<"Edad de la persona: "; cin>>edad[i];
		fflush(stdin);
		cout<<"Genero de la persona (M= Masculino, F= Femenino): "; cin.getline(genero,10,'\n');
		
//agregar y leer archivo
	ofstream grabararchivo;
	try {
		grabararchivo.open("datos.txt",ios::app);
		grabararchivo<<peso[i]<<"\t"<<altura[i]<<"\t"<<edad[i]<<"\t"<<genero<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
//mostrando datos del archivo
	cout<<"\n"<<"=============================================Datos Actuales================================================="<<endl;
	cout<<"PESO//ALTURA//EDAD//GENERO"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("datos.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
//calculando media de datos ya ingresados
	cout<<"==================================================Pomedio de datos================================================"<<endl;
	sumap=sumap+peso[i];
	mpeso=sumap/N;
	cout<<"======El promedio del peso es: "<<mpeso<<endl;
	
	sumaa=sumaa+altura[i];
	maltura=sumaa/N;
	cout<<"======El promedio de altura es: "<<maltura<<endl;
	
	sumae=sumae+edad[i];
	medad=sumae/N;
	cout<<"======El promedio de edad es: "<<medad<<endl;
	
}
}
