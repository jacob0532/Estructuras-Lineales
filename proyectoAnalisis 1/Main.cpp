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
#include <algorithm>

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

void InsertarEstudiante(DatosSistema& datosSistema) {
    string carnet, nombre, apellido, cedula, lugarResidencia;
    int edad;

    cout << "Ingrese el carnet del estudiante: ";
    cin >> carnet;

    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el apellido del estudiante: ";
    getline(cin, apellido);

    cout << "Ingrese la cédula del estudiante: ";
    cin >> cedula;

    cout << "Ingrese la edad del estudiante: ";
    cin >> edad;

    cout << "Ingrese el lugar de residencia del estudiante: ";
    cin.ignore();
    getline(cin, lugarResidencia);

    Estudiante nuevoEstudiante(carnet, nombre, apellido, cedula, edad, lugarResidencia);

    // Agregar el estudiante a la lista de estudiantes dentro de la estructura DatosSistema
    datosSistema.listaEstudiantes.push_back(nuevoEstudiante);

    cout << "Estudiante ingresado correctamente." << endl;
}

void InsertarCurso(DatosSistema& datosSistema) {
    string codigo, nombre;
    int creditos;

    cout << "Ingrese el código del curso: ";
    cin >> codigo;

    cout << "Ingrese el nombre del curso: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el número de créditos del curso: ";
    cin >> creditos;

    // Crear una instancia de Curso con los datos ingresados
    Curso nuevoCurso(codigo, nombre, creditos, list<Proyecto>()); // La lista de proyectos se inicializa vacía

    // Agregar el curso a la lista de cursos en la estructura DatosSistema
    datosSistema.listaCursos.push_back(nuevoCurso);

    cout << "Curso ingresado correctamente." << endl;
}

void InsertarComponente(DatosSistema& datosSistema) {
    string codigo, nombre, descripcion, aplicaciones;
    Clasificacion clasificacion;

    cout << "Ingrese el código del componente: ";
    cin >> codigo;

    cout << "Ingrese el nombre del componente: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la descripción del componente: ";
    getline(cin, descripcion);

    cout << "Ingrese las aplicaciones del componente: ";
    getline(cin, aplicaciones);

    cout << "Seleccione la clasificación del componente (0 para ACTIVO, 1 para PASIVO): ";
    int clasif;
    cin >> clasif;
    clasificacion = static_cast<Clasificacion>(clasif);

    // Crear una instancia de Componente con los datos ingresados
    Componente nuevoComponente(codigo, nombre, descripcion, clasificacion, aplicaciones);

    // Agregar el componente a la lista de componentes en la estructura DatosSistema
    datosSistema.listaComponentes.push_back(nuevoComponente);

    cout << "Componente ingresado correctamente." << endl;
}

void InsertarProyecto(DatosSistema& datosSistema) {
    string nombre, descripcion;
    double valorPorcentual;

    cout << "Ingrese el nombre del proyecto: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la descripción del proyecto: ";
    getline(cin, descripcion);

    cout << "Ingrese el valor porcentual del proyecto: ";
    cin >> valorPorcentual;

    // Crear una instancia de Proyecto con los datos ingresados
    Proyecto nuevoProyecto(nombre, descripcion, valorPorcentual);

    // Agregar el proyecto a la lista de proyectos en la estructura DatosSistema
    datosSistema.listaProyectos.push_back(nuevoProyecto);

    cout << "Proyecto ingresado correctamente." << endl;
}

void InsertarEstudianteListaEspera(DatosSistema& datosSistema) {
    string carnet;
    Componente tipoComponente;
    int cantidad;

    cout << "Ingrese el carnet del estudiante: ";
    cin >> carnet;

    // Buscar el estudiante en la lista de estudiantes dentro de datosSistema
    auto itEstudiante = find_if(datosSistema.listaEstudiantes.begin(), datosSistema.listaEstudiantes.end(),
        [carnet](const Estudiante& estudiante) {
            return estudiante.carnet == carnet;
        });

    if (itEstudiante == datosSistema.listaEstudiantes.end()) {
        cout << "Estudiante no encontrado. Verifique el carnet." << endl;
        return;
    }

    cout << "Ingrese el código del tipo de componente: ";
    cin >> tipoComponente.codigo;

    // Buscar el tipo de componente en la lista de componentes dentro de datosSistema
    auto itTipoComponente = find_if(datosSistema.listaComponentes.begin(), datosSistema.listaComponentes.end(),
        [tipoComponente](const Componente& componente) {
            return componente.codigo == tipoComponente.codigo;
        });

    if (itTipoComponente == datosSistema.listaComponentes.end()) {
        cout << "Tipo de componente no encontrado. Verifique el código." << endl;
        return;
    }

    cout << "Ingrese la cantidad deseada: ";
    cin >> cantidad;

    // Agregar el estudiante, tipo de componente y cantidad a la lista de espera
    datosSistema.listaEspera.estudiantes.push_back(*itEstudiante);
    datosSistema.listaEspera.tiposComponentes.push_back(*itTipoComponente);
    datosSistema.listaEspera.cantidad.push_back(cantidad);

    cout << "Estudiante agregado a la lista de espera correctamente." << endl;
}

void InsertarListaMorosos(DatosSistema& datosSistema) {
    string carnet, codigoComponente;
    int cantidadPendiente;

    cout << "Ingrese el carnet del estudiante moroso: ";
    cin >> carnet;

    // Buscar al estudiante en la lista de estudiantes
    auto itEstudiante = find_if(datosSistema.listaEstudiantes.begin(), datosSistema.listaEstudiantes.end(),
        [carnet](const Estudiante& estudiante) {
            return estudiante.carnet == carnet;
        });

    if (itEstudiante == datosSistema.listaEstudiantes.end()) {
        cout << "Estudiante no encontrado. Verifique el carnet." << endl;
        return; // Salir de la función si el estudiante no se encuentra
    }

    cout << "Ingrese el código del tipo de componente por el cual está en deuda: ";
    cin >> codigoComponente;

    // Buscar el tipo de componente en la lista de componentes
    auto itComponente = find_if(datosSistema.listaComponentes.begin(), datosSistema.listaComponentes.end(),
        [codigoComponente](const Componente& componente) {
            return componente.codigo == codigoComponente;
        });

    if (itComponente == datosSistema.listaComponentes.end()) {
        cout << "Tipo de componente no encontrado. Verifique el código." << endl;
        return; // Salir de la función si el tipo de componente no se encuentra
    }

    cout << "Ingrese la cantidad pendiente: ";
    cin >> cantidadPendiente;

    // Llamar a la función para agregar al estudiante a la lista de morosos
    datosSistema.listaMorosos.AgregarMoroso(*itEstudiante, *itComponente, cantidadPendiente);
    cout << "Estudiante agregado a la lista de morosos correctamente." << endl;
}

void InsertarTipo(DatosSistema& datosSistema) {
    string codigo, nombre, descripcion, dondeSeUtilizan;
    int cantidad;

    cout << "Ingrese el código del tipo: ";
    cin >> codigo;

    // Verificar si el código del tipo ya existe en la lista de tipos
    auto itTipoExistente = find_if(datosSistema.listaTipos.begin(), datosSistema.listaTipos.end(),
        [codigo](const Tipos& tipo) {
            return tipo.codigo == codigo;
        });

    if (itTipoExistente != datosSistema.listaTipos.end()) {
        cout << "El código del tipo ya existe. No se puede duplicar." << endl;
        return; // Salir de la función si ya existe el código del tipo
    }

    cout << "Ingrese el nombre del tipo: ";
    cin >> nombre;

    cout << "Ingrese la descripción del tipo: ";
    cin >> descripcion;

    cout << "Ingrese dónde se utilizan este tipo: ";
    cin >> dondeSeUtilizan;

    cout << "Ingrese la cantidad disponible de este tipo: ";
    cin >> cantidad;

    // Crear un objeto de tipo Tipos con los datos ingresados
    Tipos nuevoTipo(codigo, nombre, descripcion, dondeSeUtilizan, cantidad);

    // Agregar el nuevo tipo a la lista de tipos
    datosSistema.listaTipos.push_back(nuevoTipo);

    cout << "Tipo agregado correctamente." << endl;
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
                InsertarEstudiante(datosSistema);
                break;
            case 2:
                cout << "Insertar Curso." << endl;
                InsertarCurso(datosSistema);
                break;
            case 3:
                cout << "Insertar Componente." << endl;
                InsertarComponente(datosSistema);
                break;
            case 4:
                cout << "Insertar Proyecto." << endl;
                InsertarProyecto(datosSistema);
                break;
            case 5:
                cout << "Insertar Lista de Espera." << endl;
                InsertarEstudianteListaEspera(datosSistema);
                break;
            case 6:
                cout << "Insertar Lista de Morosos." << endl;
                InsertarListaMorosos(datosSistema);
                break;
            case 7:
                cout << "Insertar Tipos." << endl;
                InsertarTipo(datosSistema);
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
