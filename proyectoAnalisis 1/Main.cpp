#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include "Curso.h"
#include "Estudiante.h"
#include "Componente.h"

using namespace std;

void menu(){
    int opcionMenu;
    bool salir=false;
    while(salir!=true){
        cout<<"\n";
        cout<<"------------------Menu-------------------------------"<<endl;
        cout<<"1.Insertar Datos"<<endl;
        cout<<"2.Modificar Datos"<<endl;
        cout<<"3.Borrar Estudiante"<<endl;
        cout<<"4.Consultas"<<endl;
        cout<<"5.Reportes"<<endl;
        cout<<"6.salir"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Seleccione una opcion:";
        cin>>opcionMenu;
        switch(opcionMenu){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;  
            case 6:
                salir=true;
                break;
        }
    }
}

int main() {
    system("cls");
    menu();
    return 0;
}
