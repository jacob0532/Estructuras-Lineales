#include <iostream>

#include <stdlib.h>

#include <string>

#include <list>

#include <ctime>

using namespace std;

list<int> arrayEnteros;
list<char> arrayChar;

list<list<int>> matrizEnteros;
list<list<string>> matrizStrings;

void imprimirMatrizEnterosAux(list<int>*);
void imprimirMatrizStringsAux(list<string>*);
int aparicionesEnStringAux(string palabra);

void cargarArrayEnteros(int* n){
	arrayEnteros.clear();
	srand(time(nullptr));
	for (int i = 0; i < *n; ++i)
	{
		arrayEnteros.push_back(rand() % 100);
	}
}

void cargarArrayChar(int* m){
	arrayChar.clear();
	char letra;
	for (int i = 0; i < *m; ++i)
	{
		cout<<"Digite el elemento de la posicion "<<i<<" del arreglo de char: [1 LETRA]"<<endl;
		cin>>letra;
		arrayChar.push_back(letra);	
	}
}
void cargarMatrizEnteros(int* n, int* m){
	matrizEnteros.clear();
	list<int> varArrayEnteros;
	list<int>::iterator pos;
	pos = arrayEnteros.begin();
	for (int i = 0; i < *n; ++i)
	{
		for (int j = 0; j < *m; ++j)
		{
			varArrayEnteros.push_back(*pos);
			pos++;
			if(pos==arrayEnteros.end()){
				pos = arrayEnteros.begin();
			}
		}
		matrizEnteros.push_back(varArrayEnteros);
		varArrayEnteros.clear();
	}
}

void cargarMatrizStrings(int* n, int* m){
	matrizStrings.clear();
	list<string> varArrayStrings;
	string palabra = "";
	for (int i = 0; i < *n; ++i)
	{
		for (int j = 0; j < *m; ++j)
		{
			cout<<"Digite el elemento de la posicion ["<<i<<","<<j<<"] de la matriz de strings:";
	 	    cin >> palabra;
	 	    varArrayStrings.push_back(palabra);
		}
		matrizStrings.push_back(varArrayStrings);
		varArrayStrings.clear();
	}
}

void imprimirArrayEnteros(){
	list<int>::iterator pos;
	pos = arrayEnteros.begin();
	cout<<endl;
	while(pos!=arrayEnteros.end()){
		cout<<*pos<<", ";
		pos++;
	}
	cout <<"\n\tfin de la lista.\n"<<endl;
}

void imprimirArrayChar(){
	list<char>::iterator pos;
	pos = arrayChar.begin();
	cout<<endl;
	while(pos!=arrayChar.end()){
		cout<<*pos<<", ";
		pos++;
	}
	cout <<"\n\tfin de la lista.\n"<<endl;
}

void imprimirMatrizEnteros(){
	list<list<int>>::iterator pos;
	pos = matrizEnteros.begin();
	while(pos!=matrizEnteros.end()){
		imprimirMatrizEnterosAux(&*pos);
		pos++;
	}
	cout <<"\n\tfin de la lista.\n"<<endl;
}

void imprimirMatrizEnterosAux(list<int>* listEnteros){
	list<int>::iterator pos2;
	pos2 = listEnteros->begin();
	cout<<endl;
	while(pos2!=listEnteros->end()){
		cout<<*pos2<<", ";
		pos2++;
	}
}

void imprimirMatrizStrings(){
	list<list<string>>::iterator pos;
	pos = matrizStrings.begin();
	while(pos!=matrizStrings.end()){
		imprimirMatrizStringsAux(&*pos);
		pos++;
	}
	cout <<"\n\tfin de la lista.\n"<<endl;
}

void imprimirMatrizStringsAux(list<string>* listStrings){
	list<string>::iterator pos2;
	pos2 = listStrings->begin();
	cout<<endl;
	while(pos2!=listStrings->end()){
		cout<<*pos2<<", ";
		pos2++;
	}
}
void aparicionesEnString(int* n, int* m){
	cout<<"\n"<<endl;
    int celda[2];
    int maximo=0;
    list<list<string>>::iterator pos;
    list<string>::iterator pos2;
    pos = matrizStrings.begin();
	for(int fila=0;fila<*n;fila++){
		pos2 = pos->begin();
		for(int columna=0;columna<*m;columna++){
			int apariciones= aparicionesEnStringAux(*pos2);
			if(maximo<apariciones){
				maximo=apariciones;
				celda[0]=fila;
				celda[1]=columna;
			}
			pos2++;
		}
		pos++;
	}
	cout<<"la celda ["<<celda[0]<<","<<celda[1]<<"]"<<" tiene "<<maximo<<" char de los que aparecen en el arreglo."<<endl;
}


int aparicionesEnStringAux(string palabra){
    int apariciones = 0;
    for (char c : arrayChar) {
        if (palabra.find(c) != string::npos) {
            apariciones++;
        }
    }
    return apariciones;
}


void menu(){
	int opcionMenu;
	bool salir=false;
	int n;
	int m;
	cout<<"Digite el Tamano n del array de enteros: ";
	cin >>n;
	cout<<"Digite el Tamano m del array de char: ";
	cin >>m;
	while(salir!=true){
		cout<<"\n";
		cout<<"n: "<<n<<" m: "<<m<<endl;
		cout<<"------------------Menu-------------------------------"<<endl;
		cout<<"1.Llenar el arreglo de enteros con numeros random"<<endl;
		cout<<"2.llenar el arreglo de char"<<endl;
		cout<<"3.llenar la matriz con los datos del arreglo"<<endl;
		cout<<"4.rellenar la matriz de strings con datos ingresados por el usuario"<<endl;
		cout<<"5.Indicar cual celda de la matriz tiene mas char de los almacenados en el arreglo"<<endl;
		cout<<"6.salir"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"Seleccione una opcion:";
		cin>>opcionMenu;
		switch(opcionMenu){
			case 1:
				cargarArrayEnteros(&n);
				imprimirArrayEnteros();
				break;
			case 2:
				cargarArrayChar(&m);
				imprimirArrayChar();
				break;
			case 3:
				cargarMatrizEnteros(&n,&m);
				cout<<"Matriz [ENTEROS]"<<n<<"x"<<m<<endl;
				imprimirMatrizEnteros();
				break;
			case 4:
				cargarMatrizStrings(&n,&m);
				cout<<"Matriz [PALABRAS] "<<n<<"x"<<m<<endl;
				imprimirMatrizStrings();
				break;
			case 5:
				aparicionesEnString(&n,&m);
				break;	
			case 6:
				salir=true;
				break;
		}
	}
}


int main (){
	system("cls");
	menu();
	cout << "Presiona Enter para continuar...";
    getchar(); // Esperar a que el usuario presione Enter
	return 0;
}




