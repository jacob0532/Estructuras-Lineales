#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include "Curso.h"
#include "Estudiante.h"
#include "Componente.h"

using namespace std;

void menuInserciones(){
    int opcionInserciones;
    bool salirInserciones = false;
    while (salirInserciones!=true) {
        cout << "\n";
        cout << "-------- Menú de Inserciones --------" << endl;
        cout << "1. Ingresar Estudiante" << endl;
        cout << "2. Ingresar Curso" << endl;
        cout << "3. Ingresar Componente" << endl;
        cout << "4. Ingresar Proyecto" << endl;
        cout << "5. Ingresar Lista de Espera" << endl;
        cout << "6. Ingresar Lista de Morosos" << endl;
        cout << "7. Ingresar Tipos" << endl;
        cout << "8. Volver al Menú Principal" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opción:";
        cin >> opcionInserciones;
        switch(opcionInserciones){
            case 1:
                cout << "Insertar Estudiante." << endl;
                break;
            case 2:
                cout << "Insertar Curso." << endl;
                break;
            case 3:
                cout << "Insertar Componente." << endl;
                break;
            case 4:
                cout << "Insertar Proyecto." << endl;
                break;
            case 5:
                cout << "Insertar Lista de Espera." << endl;
                break;
            case 6:
                cout << "Insertar Lista de Morosos." << endl;
                break;
            case 7:
                cout << "Insertar Tipos." << endl;
                break;
            case 8:
                salirInserciones = true;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }
}

void menuEdiciones(){
    int opcionEdicion;
    bool salirEdicion = false;
    while (salirEdicion!=true) {
        cout << "\n";
        cout << "-------- Menú de Ediciones --------" << endl;
        cout << "1. Editar Cursos" << endl;
        cout << "2. Editar Componentes" << endl;
        cout << "3. Volver al Menú Principal" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opción:";
        cin >> opcionEdicion;
        switch(opcionEdicion){
            case 1:
                cout << "Editar Cursos." << endl;
                break;
            case 2:
                cout << "Editar Componentes" << endl;
                break;
            case 3:
                salirEdicion = true;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }
}

void consultas(){
    int opcionConsulta;
    bool salirConsutla = false;
    while (salirConsutla!=true) {
        cout << "\n";
        cout << "-------- Menú de Consultas --------" << endl;
        cout << "1. Curso que requiere mas componentes electronicos en general" << endl;
        cout << "2. Estudiante con mas proyectos asignados" << endl;
        cout << "3. Proyecto que requiere mas tipos de componentes" << endl;
        cout << "4. Estudiantes que deben esperar por mas de un tipo de comopnente" << endl;
        cout << "5. Primeros tres tipos de componente requeridos por escasez" << endl;
        cout << "6. Estudiante con mas tipos de componente prestados" << endl;
        cout << "7. Estudiante con mayor morosidad" << endl;
        cout << "8. Volver al Menú Principal" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opción:";
        cin >> opcionConsulta;
        switch(opcionConsulta){
            case 1:
                cout << "1. Curso que requiere mas componentes electronicos en general" << endl;
                break;
            case 2:
                cout << "2. Estudiante con mas proyectos asignados" << endl;
                break;
            case 3:
                cout << "3. Proyecto que requiere mas tipos de componentes" << endl;
                break;
            case 4:
                cout << "4. Estudiantes que deben esperar por mas de un tipo de comopnente" << endl;
                break;
            case 5:
                cout << "5. Primeros tres tipos de componente requeridos por escasez" << endl;
                break;
            case 6:
                cout << "6. Estudiante con mas tipos de componente prestados" << endl;
                break;
            case 7:
                cout << "7. Estudiante con mayor morosidad" << endl;
                break;
            case 8:
                salirConsutla = true;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }
}

void reportes(){
    int opcionReporte;
    bool salirReporte = false;
    while (salirReporte!=true) {
        cout << "\n";
        cout << "-------- Menú de Reportes --------" << endl;
        cout << "1. Información de todas las listas" << endl;
        cout << "2. Estudiantes sin matricula" << endl;
        cout << "3. Estudiantes sin préstamos" << endl;
        cout << "4. Tipos de componentes con cantidad 0." << endl;
        cout << "5. Volver al Menú Principal" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opción:";
        cin >> opcionReporte;
        switch(opcionReporte){
            case 1:
                cout << "1. Información de todas las listas" << endl;
                break;
            case 2:
                cout << "2. Estudiantes sin matricula" << endl;
                break;
            case 3:
                cout << "3. Estudiantes sin préstamos" << endl;
                break;
            case 4:
                cout << "4. Tipos de componentes con cantidad 0." << endl;
                break;
            case 5:
                salirReporte = true;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }
}

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
                menuInserciones();
                break;
            case 2:
                menuEdiciones();
                break;
            case 3:
                cout << "Ingrese el carnet del estudiante a borrar: ";
                //string carnet;
                //cin >> carnet;
                //eliminarEstudiante();
                break;
            case 4:
                consultas();
                break;
            case 5:
                reportes();
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
