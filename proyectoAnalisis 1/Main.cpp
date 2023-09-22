#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime>   
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
        componente.tipos = datosSistema.listaTipos;

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
        componente.tipos = datosSistema.listaTipos;

        // Insertar el componente al final de la lista
        datosSistema.listaComponentes.push_back(componente);
    }
    for (int i = 1; i <= 10; ++i) {
        string nombre = "Proyecto" + to_string(i);
        string descripcion = "Descripción del proyecto " + to_string(i);
        double valorPorcentual = 1;

        // Crear un objeto Proyecto utilizando el constructor
        Proyecto proyecto(nombre, descripcion, valorPorcentual);

        ComponenteRequerido componenteRequerido;
        srand(static_cast<unsigned int>(std::time(nullptr)));
        int numeroAleatorio = rand() % 10;
        auto it = datosSistema.listaComponentes.begin();
        advance(it, numeroAleatorio);
        componenteRequerido.tipoComponente = *it;
        componenteRequerido.cantMinRequerida = i * 2;
        proyecto.compRequeridos.push_back(componenteRequerido);
        datosSistema.listaProyectos.push_back(proyecto);
    }
    
    // Agregar proyectos específicos de datosSistema.listaProyectos a la lista de proyectos del curso
    list<Proyecto> proyectos;
    auto it = datosSistema.listaProyectos.begin();
    for (int i = 1; i <= 10; ++i) {
        string codigo = "C" + to_string(i);
        string nombre = "CursoElectro" + to_string(i);
        int creditos = 3 + i;
        proyectos.push_back(*it);
        Curso curso(codigo, nombre, creditos, proyectos);
        // Insertar el curso al inicio de la lista
        datosSistema.listaCursos.push_front(curso);
        it++;
        proyectos.clear();
    }
    string nombres[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivan", "Jack"};
    for (int i = 1; i <= 10; ++i) {
        string carnet = to_string(10 + i) + "2020";
        string nombre = nombres[i - 1];
        string apellido = "Apellido" + to_string(i);
        string cedula = "20365" + to_string(1000 + i);
        int edad = 20 + i;
        string lugarResidencia = "SanJose" + to_string(i);

        Estudiante estudiante(carnet, nombre, apellido, cedula, edad, lugarResidencia);



        // Assign the list of courses to the Estudiante
        auto endIt = datosSistema.listaCursos.begin();
        advance(endIt, 3);  // Advance to position 5 (not included)
        estudiante.listaMatricula.assign(datosSistema.listaCursos.begin(), endIt);

        auto it = datosSistema.listaEstudiantes.begin();
        while (it != datosSistema.listaEstudiantes.end() && it->carnet > carnet) {
            ++it;
        }
        datosSistema.listaEstudiantes.insert(it, estudiante);
    }
}
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
                //menuInserciones();
                agregarDatosAlDatosSistema();
                /*for (auto& tipo : datosSistema.listaTipos) {
                    cout << tipo.ToString() << "\n\n";
                }*/
                /*for (auto& componente : datosSistema.listaComponentes) {
                    cout << componente.ToString() << "\n\n";
                }*/
                /*for (const auto& proyecto : datosSistema.listaProyectos) {
                    cout << proyecto.ToString() << "\n\n";
                }*/
                for (auto& estudiante : datosSistema.listaEstudiantes) {
                    cout << estudiante.ToString() << "\n\n";
                }
                /*for (auto& curso : datosSistema.listaCursos) {
                    cout << curso.ToString() << "\n\n";
                }*/
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
