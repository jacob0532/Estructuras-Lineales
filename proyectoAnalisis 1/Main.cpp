#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include "Curso.h"
#include "Estudiante.h"
#include "Componente.h"
#include "ListaEspera.h"
#include "ListaMorosos.h"
#include "Proyecto.h"
#include "Tipos.h"

using namespace std;

struct DatosSistema {
    list<Componente> listaComponentes;
    list<Curso> listaCursos;
    list<Estudiante> listaEstudiantes;
    ListaEspera listaEspera;
    ListaMorosos listaMorosos;
    list<Proyecto> listaProyectos;
    list<Tipos> listaTipos;
};

DatosSistema datosSistema;  // Instancia de DatosDatosSistema

void agregarDatosAlDatosSistema(){
    for (int i = 1; i <= 5; ++i) {
        string codigo = "T" + to_string(i);
        string nombre = "Tipo" + to_string(i);
        string descripcion = "Descripcion del tipo " + to_string(i);
        string dondeSeUtilizan = "Donde se utilizan el tipo " + to_string(i);
        int cantidad = 1 + i;

        Tipos tipo(codigo, nombre, descripcion, dondeSeUtilizan, cantidad);

        datosSistema.listaTipos.push_front(tipo);
    }
    string nombresPasivos[] = {"Resistor", "Condensador", "Inductor", "Diodo", "Transformador"};
    for (int i = 0; i < 5; ++i) {
        string codigo = "CP" + to_string(i + 1);
        string nombre = nombresPasivos[i];
        string descripcion = "Componente electrico pasivo - " + nombre;
        Clasificacion clasificacion = PASIVO;
        string aplicaciones = "Aplicaciones del componente " + nombre;

        // Crear un objeto Componente utilizando el constructor
        Componente componente(codigo, nombre, descripcion, clasificacion, aplicaciones);

        // Insertar el componente al final de la lista
        datosSistema.listaComponentes.push_back(componente);
    }

    // Nombres realistas para componentes eléctricos activos
    string nombresActivos[] = {"Transistor", "Amplificador operacional", "Diodo emisor de luz (LED)", "Triac", "Optoacoplador"};
    for (int i = 0; i < 5; ++i) {
        string codigo = "CA" + to_string(i + 1);
        string nombre = nombresActivos[i];
        string descripcion = "Componente electrico activo - " + nombre;
        Clasificacion clasificacion = ACTIVO;
        string aplicaciones = "Aplicaciones del componente " + nombre;

        // Crear un objeto Componente utilizando el constructor
        Componente componente(codigo, nombre, descripcion, clasificacion, aplicaciones);

        // Insertar el componente al final de la lista
        datosSistema.listaComponentes.push_back(componente);
    }
    /*for (int i = 1; i <= 10; ++i) {
        string carnet = to_string(10 + i) + "2020";
        string nombre = "Nombre" + to_string(i);
        string apellido = "Apellido" + to_string(i);
        string cedula = "20365" + to_string(1000 + i);
        int edad = 20 + i;
        string lugarResidencia = "SanJose";

        Estudiante estudiante(carnet, nombre, apellido, cedula, edad, lugarResidencia);

        auto it = datosSistema.listaEstudiantes.begin();
        while (it != datosSistema.listaEstudiantes.end() && it->carnet > carnet) {
            ++it;
        }
        datosSistema.listaEstudiantes.insert(it, estudiante);
    }
    for (int i = 1; i <= 10; ++i) {
        string codigo = "C" + to_string(i);
        string nombre = "Curso" + to_string(i);
        int creditos = 3 + i;

        // Crear un objeto Curso utilizando el constructor
        Curso curso(codigo, nombre, creditos, list<Proyecto>());

        // Insertar el curso al inicio de la lista
        sistema.listaCursos.push_front(curso);
    }*/
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
