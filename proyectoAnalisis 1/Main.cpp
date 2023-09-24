#include <iostream>         //se incluyen las librerías neceasarias
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
#include <algorithm>
#include <unordered_set> 
#include <unordered_map>
#include <set>  // Add this line to include set

using namespace std;

//Se definen las lista para trabajar en el programa
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

//Funcion que permite agregar los datos necesarios al inciar el programa.
//Fecha de inicio: 18/9/2023
//Fecha última modificación: 21/9/2023.
void agregarDatosAlDatosSistema(){
    string nombresTipos[] = {"Tipo led","Tipo inductor","Tipo cristal","Tipo metal","Tipo E13B"};
    for (int i = 0; i < 5; ++i) {
        string codigo = "T" + to_string(i);
        string nombre = nombresTipos[i];
        string descripcion = "Descripcion del tipo " + to_string(i);
        string dondeSeUtilizan = "Donde se utilizan el tipo " + to_string(i);
        int cantidad = 1 + i;

        Tipos tipo(codigo, nombre, descripcion, dondeSeUtilizan, cantidad);

        datosSistema.listaTipos.push_front(tipo);
    }
    string nombresPasivos[] = {"Resistencias", "Capacitores", "Inductores", "Condensadores", "Transformadores"};
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

    // Nombres para componentes eléctricos activos
    string nombresActivos[] = {"Transistores", "Amplificadores", "Diodos", "Triacs", "Contadores"};
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
        string descripcion = "descripcion del proyecto " + to_string(i);
        double valorPorcentual = 1;

        // Crear un objeto Proyecto utilizando el constructor
        Proyecto proyecto(nombre, descripcion, valorPorcentual);

        ComponenteRequerido componenteRequerido;
        srand(static_cast<unsigned int>(std::time(nullptr)));
        int numeroAleatorio = rand() % 10;
        auto it = datosSistema.listaTipos.begin();
        advance(it, numeroAleatorio);
        componenteRequerido.tipoComponente = *it;
        componenteRequerido.cantMinRequerida = i * 2;
        proyecto.compRequeridos.push_back(componenteRequerido);
        datosSistema.listaProyectos.push_back(proyecto);
    }
    
    // Agregar proyectos la lista de proyectos del curso
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

        // Asignar una lista de cursos al estuidiante
        auto endIt = datosSistema.listaCursos.begin();
        advance(endIt, i);  
        estudiante.listaMatricula.assign(datosSistema.listaCursos.begin(), endIt);

        auto it = datosSistema.listaEstudiantes.begin();
        while (it != datosSistema.listaEstudiantes.end() && it->carnet > carnet) {
            ++it;
        }
        datosSistema.listaEstudiantes.insert(it, estudiante);
    }
}


void ImprimirNombreYCarnet(const list<Estudiante>& listaEstudiantes) {
    cout << "=== Estudiantes ===" << endl;
    for (const Estudiante& estudiante : listaEstudiantes) {
        cout << "Nombre: " << estudiante.nombre << ", Carnet: " << estudiante.carnet << endl;
    }
}

void ImprimirCodigoComponente(const list<Componente>& listaComponentes) {
    cout << "=== Componentes ===" << endl;
    for (const Componente& componente : listaComponentes) {
        cout << "Nombre: " << componente.nombre << ", Codigo: " << componente.codigo << endl;
    }
}

//Funcion que permite insertar un estudiane al sistema, lo incluye en la lista de estudiantes definida el inicio.
//Fecha de inicio: 17/9/2023
//Fecha última modificación: 21/9/2023.

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

//Funcion que permite insertar un Curso al sistema, lo incluye en la lista de cursos definida el inicio.
//Fecha de inicio: 18/9/2023
//Fecha última modificación: 21/9/2023.

void InsertarCurso(DatosSistema& datosSistema) {
    string codigo, nombre;
    int creditos;

    cout << "Ingrese el codigo del curso: ";
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

//Funcion que permite insertar un componente al sistema, lo incluye en la lista de componentes definida el inicio.
//Fecha de inicio: 17/9/2023
//Fecha última modificación: 21/9/2023.
void InsertarComponente(DatosSistema& datosSistema) {
    string codigo, nombre, descripcion, aplicaciones;
    Clasificacion clasificacion;

    cout << "Ingrese el codigo del componente: ";
    cin >> codigo;

    cout << "Ingrese el nombre del componente: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la descripcion del componente: ";
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

//Funcion que permite insertar un proyectos al sistema, lo incluye en la lista de proyectos definida el inicio.
//Fecha de inicio: 17/9/2023
//Fecha última modificación: 21/9/2023.
void InsertarProyecto(DatosSistema& datosSistema) {
    string nombre, descripcion;
    double valorPorcentual;

    cout << "Ingrese el código del curso existente: ";
    string codigoCurso;
    cin >> codigoCurso;

    // Buscar el curso en la lista de cursos dentro de datosSistema
    auto itCurso = find_if(datosSistema.listaCursos.begin(), datosSistema.listaCursos.end(),
        [codigoCurso](const Curso& curso) {
            return curso.codigo == codigoCurso;
        });

    if (itCurso == datosSistema.listaCursos.end()) {
        cout << "Curso no encontrado. Verifique el código." << endl;
        return;
    }

    cout << "Ingrese el nombre del proyecto: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la descripcion del proyecto: ";
    getline(cin, descripcion);

    cout << "Ingrese el valor porcentual del proyecto: ";
    cin >> valorPorcentual;

    // Crear una instancia de Proyecto con los datos ingresados
    Proyecto nuevoProyecto(nombre, descripcion, valorPorcentual);

    // Solicitar componentes requeridos al proyecto
    char agregarComponente;
    do {
        string codigoComponente;
        int cantidadRequerida;

        cout << "¿Desea agregar un componente requerido al proyecto? (S/N): ";
        cin >> agregarComponente;

        if (agregarComponente == 'S' || agregarComponente == 's') {
            cout << "Ingrese el código del componente requerido: ";
            cin >> codigoComponente;

            // Buscar el componente en la lista de componentes dentro de datosSistema
            auto itComponente = find_if(datosSistema.listaTipos.begin(), datosSistema.listaTipos.end(),
                [codigoComponente](auto& componente) {
                    return componente.codigo == codigoComponente;
                });

            if (itComponente != datosSistema.listaTipos.end()) {
                cout << "Ingrese la cantidad requerida de " << itComponente->nombre << ": ";
                cin >> cantidadRequerida;

                // Crear un objeto ComponenteRequerido y agregarlo al proyecto
                ComponenteRequerido componenteRequerido;
                componenteRequerido.tipoComponente = *itComponente;
                componenteRequerido.cantMinRequerida = cantidadRequerida;

                nuevoProyecto.compRequeridos.push_back(componenteRequerido);
                cout << "Componente requerido agregado correctamente." << endl;
            } else {
                cout << "Componente no encontrado. Verifique el código." << endl;
            }
        }
    } while (agregarComponente == 'S' || agregarComponente == 's');

    // Agregar el proyecto a la lista de proyectos del curso
    itCurso->listaProyectos.push_back(nuevoProyecto);
    datosSistema.listaProyectos.push_back(nuevoProyecto);

    cout << "Proyecto ingresado correctamente." << endl;
}


//Funcion que permite insertar un estudiane y el componente solicitado en una lista de espera, lo incluye en la lista de espera definida el inicio.
//Fecha de inicio: 20/9/2023
//Fecha última modificación: 21/9/2023.
void InsertarEstudianteListaEspera(DatosSistema& datosSistema) {
    string carnet;
    string codigoTipoComponente; // Cambiamos a string
    int cantidad;

    // Imprimir lista de estudiantes
    ImprimirNombreYCarnet(datosSistema.listaEstudiantes);
    
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

    cout << "\n***Componentes y Tipos existentes***\n";
    cout << " ";

    // Imprimir lista de componentes y sus subtipos
    for (const Componente& componente : datosSistema.listaComponentes) {
        cout << "Nombre del componente: " << componente.nombre << endl;
        cout << "Tipos:" << endl;
        for (const Tipos& tipo : componente.tipos) {
            cout << "Código: " << tipo.codigo << ", Nombre: " << tipo.nombre << endl;
        }
    }

    cout << "\nIngrese el código del tipo de componente: "; // Solicita el código del tipo de componente
    cin >> codigoTipoComponente;

    // Buscar el tipo de componente en la lista de componentes dentro de datosSistema
    auto itTipoComponente = find_if(datosSistema.listaComponentes.begin(), datosSistema.listaComponentes.end(),
        [codigoTipoComponente](const Componente& componente) {
            return any_of(componente.tipos.begin(), componente.tipos.end(),
                [codigoTipoComponente](const Tipos& tipo) {
                    return tipo.codigo == codigoTipoComponente;
                });
        });

    if (itTipoComponente == datosSistema.listaComponentes.end()) {
        cout << "Tipo de componente no encontrado. Verifique el código." << endl;
        return;
    }

    cout << "Ingrese la cantidad deseada: ";
    cin >> cantidad;

    // Verificar si el estudiante ya está en la lista de espera
    auto itListaEsperaEstudiante = find_if(datosSistema.listaEspera.estudiantes.begin(), datosSistema.listaEspera.estudiantes.end(),
        [carnet](const Estudiante& estudiante) {
            return estudiante.carnet == carnet;
        });

    if (itListaEsperaEstudiante != datosSistema.listaEspera.estudiantes.end()) {
        cout << "El estudiante ya está en la lista de espera." << endl;
        return;
    }

    // Agregar el estudiante, tipo de componente y cantidad a la lista de espera
    datosSistema.listaEspera.estudiantes.push_back(*itEstudiante);
    datosSistema.listaEspera.tiposComponentes.push_back(*itTipoComponente);
    datosSistema.listaEspera.cantidad.push_back(cantidad);

    cout << "Estudiante agregado a la lista de espera correctamente." << endl;
}


//Funcion que permite insertar un estudiane en una lista de morosos, lo incluye en la lista de morosos definida el inicio.
//Fecha de inicio: 20/9/2023
//Fecha última modificación: 21/9/2023.
void InsertarListaMorosos(DatosSistema& datosSistema) {
    string carnet, codigoComponente;
    int cantidadPendiente;
    ImprimirNombreYCarnet(datosSistema.listaEstudiantes);
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
    ImprimirCodigoComponente(datosSistema.listaComponentes);
    cout << "Ingrese el codigo del tipo de componente por el cual está en deuda: ";
    cin >> codigoComponente;

    // Buscar el tipo de componente en la lista de componentes
    auto itComponente = find_if(datosSistema.listaComponentes.begin(), datosSistema.listaComponentes.end(),
        [codigoComponente](const Componente& componente) {
            return componente.codigo == codigoComponente;
        });

    if (itComponente == datosSistema.listaComponentes.end()) {
        cout << "Tipo de componente no encontrado. Verifique el codigo." << endl;
        return; // Salir de la función si el tipo de componente no se encuentra
    }

    cout << "Ingrese la cantidad pendiente: ";
    cin >> cantidadPendiente;

    // Llamar a la función para agregar al estudiante a la lista de morosos
    datosSistema.listaMorosos.AgregarMoroso(*itEstudiante, *itComponente, cantidadPendiente);
    cout << "Estudiante agregado a la lista de morosos correctamente." << endl;
}

//Funcion que permite insertar un tipo de componente al sistema, lo incluye en la lista de tipos definida el inicio.
//Fecha de inicio: 17/9/2023
//Fecha última modificación: 21/9/2023.
void InsertarTipo(DatosSistema& datosSistema) {
    string codigoComponente, codigoTipo, nombre, descripcion, dondeSeUtilizan;
    int cantidad;
    ImprimirCodigoComponente(datosSistema.listaComponentes);
    cout << "Ingrese el codigo del componente al que desea agregar el tipo: ";
    cin >> codigoComponente;

    // Verificar si el codigo del componente existe en la lista de componentes
    auto itComponente = find_if(datosSistema.listaComponentes.begin(), datosSistema.listaComponentes.end(),
        [codigoComponente](const Componente& componente) {
            return componente.codigo == codigoComponente;
        });

    if (itComponente == datosSistema.listaComponentes.end()) {
        cout << "El codigo del componente no existe en la lista de componentes." << endl;
        return; // Salir de la función si el codigo del componente no existe
    }

    cout << "Ingrese el codigo del tipo: ";
    cin >> codigoTipo;

    // Verificar si el codigo del tipo ya existe en la lista de tipos
    auto itTipoExistente = find_if(datosSistema.listaTipos.begin(), datosSistema.listaTipos.end(),
        [codigoTipo](const Tipos& tipo) {
            return tipo.codigo == codigoTipo;
        });

    if (itTipoExistente != datosSistema.listaTipos.end()) {
        cout << "El codigo del tipo ya existe. No se puede duplicar." << endl;
        return; // Salir de la función si ya existe el codigo del tipo
    }

    cin.ignore();

    cout << "Ingrese el nombre del tipo: ";
    getline(cin, nombre);

    cout << "Ingrese la descripcion del tipo: ";
    getline(cin, descripcion);

    cout << "Ingrese dónde se utilizan este tipo: ";
    getline(cin, dondeSeUtilizan);

    cout << "Ingrese la cantidad disponible de este tipo: ";
    cin >> cantidad;

    // Crear un objeto de tipo Tipos con los datos ingresados
    Tipos nuevoTipo(codigoTipo, nombre, descripcion, dondeSeUtilizan, cantidad);

    // Agregar el nuevo tipo a la lista de tipos
    datosSistema.listaTipos.push_back(nuevoTipo);

    // Agregar el nuevo tipo a la lista de tipos del componente correspondiente
    itComponente->tipos.push_back(nuevoTipo);

    cout << "Tipo agregado correctamente al componente." << endl;
}

void DevolverPrestamo(DatosSistema& datosSistema) {
    string carnet;
    string codigoTipoComponente;
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

    cout << "Ingrese el código del tipo de componente que desea devolver: ";
    cin >> codigoTipoComponente;

    // Buscar el tipo de componente en la lista de componentes dentro de datosSistema
    auto itTipoComponente = find_if(datosSistema.listaComponentes.begin(), datosSistema.listaComponentes.end(),
        [codigoTipoComponente](const Componente& componente) {
            return componente.codigo == codigoTipoComponente;
        });

    if (itTipoComponente == datosSistema.listaComponentes.end()) {
        cout << "Tipo de componente no encontrado. Verifique el código." << endl;
        return;
    }

    cout << "Ingrese la cantidad a devolver: ";
    cin >> cantidad;

    // Buscar el préstamo del estudiante para el tipo de componente y cantidad especificados
    auto itPrestamo = find_if(itEstudiante->listaPrestamos.begin(), itEstudiante->listaPrestamos.end(),
        [codigoTipoComponente, cantidad](const PrestamoTiposC& prestamo) {
            return prestamo.tipoComponente.codigo == codigoTipoComponente &&
                   prestamo.cantidad == cantidad;
        });

    if (itPrestamo != itEstudiante->listaPrestamos.end()) {
        // Devolver el préstamo
        itEstudiante->listaPrestamos.erase(itPrestamo);
        cout << "Préstamo devuelto correctamente." << endl;
    } else {
        cout << "No se encontró un préstamo con los datos especificados." << endl;
    }
}


//FUNCIONES DE CONSULTA

//Funcion que permite contabilizar el total de componentes
//Fecha de inicio: 21/9/2023
//Fecha última modificación: 22/9/2023.
int countTotalComponents(const std::list<ComponenteRequerido>& compRequeridos) {
    int totalComponents = 0;

    for (const auto& componente : compRequeridos) {
        totalComponents += componente.cantMinRequerida;
    }

    return totalComponents;
}

//Funcion que permite la primera consulta: curso que requiere mas componentes.
//Fecha de inicio: 21/9/2023
//Fecha última modificación: 22/9/2023.
Curso cursoReqMasComponentes() {
    Curso cursoConMasComponentes;
    int maxTotalComponents = 0;

    for (const auto& curso : datosSistema.listaCursos) {
        int totalComponents = 0;


        for (const auto& proyecto : curso.listaProyectos) {
            totalComponents += countTotalComponents(proyecto.compRequeridos);
        }


        if (totalComponents > maxTotalComponents) {
            maxTotalComponents = totalComponents;
            cursoConMasComponentes = curso;
        }
    }
    cout << cursoConMasComponentes.ToString() << "\n\n";
    return cursoConMasComponentes;
}

//Funcion que permite la segunda consulta: estudiante con mas proyectos asignados
//Fecha de inicio: 21/9/2023
//Fecha última modificación: 22/9/2023.
list<Estudiante> estuConMasProyectos() {
    list<Estudiante> estConMasProyectos;
    int maxProyectos = 0;

    for (const auto& estudiante : datosSistema.listaEstudiantes) {
        int totalProyectos = 0;

        // Calcula el tota de proyecto de cada curso en la matricula del estudiante
        for (const auto& curso : estudiante.listaMatricula) {
            totalProyectos += curso.listaProyectos.size();
        }

        if (totalProyectos > maxProyectos) {
            maxProyectos = totalProyectos;
            estConMasProyectos.clear();
            estConMasProyectos.push_back(estudiante);
        } else if (totalProyectos == maxProyectos) {
            estConMasProyectos.push_back(estudiante);
        }
    }

    if (estConMasProyectos.size() > 1) {
        for (auto& estudiante : estConMasProyectos) {
            cout << estudiante.ToString() << "\n\n";
        }
    }else if (estConMasProyectos.size() == 1) {
    // Imprime el estudiante con mas proyectos
    cout << "Estudiante con mas proyectos (" << maxProyectos << " proyectos):\n";
    cout << estConMasProyectos.front().ToString() << "\n";
    } else {
        cout << "No hay estudiantes con proyectos.\n";
    }


    return estConMasProyectos;
}

//Funcion que permite la tercera consulta: proyecto que requiere mas tipos de componentes
//Fecha de inicio: 21/9/2023
//Fecha última modificación: 22/9/2023.
Proyecto proyectoConMasTiposComponentes() {
    Proyecto proyectoConMasTipos;
    int maxComponentTypes = 0;

    for (const auto& proyecto : datosSistema.listaProyectos) {
        unordered_set<string> uniqueComponentTypes;

        // Cuenta los tipos unico de componentesr para el proyecto
        for (const auto& componenteRequerido : proyecto.compRequeridos) {
            uniqueComponentTypes.insert(componenteRequerido.tipoComponente.nombre);
        }

        // Actualiza el proyecto con mas tipos de componentes unicos
        if (uniqueComponentTypes.size() > maxComponentTypes) {
            maxComponentTypes = uniqueComponentTypes.size();
            proyectoConMasTipos = proyecto;
        }
    }
    cout << proyectoConMasTipos.ToString() << "\n\n";
    return proyectoConMasTipos;
}


//Funcion para matricular un estudiante
void MatricularEstudiante(DatosSistema& datosSistema) {
    string carnet;
    
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

    // Preguntar si el usuario quiere matricular al estudiante en cursos
    char deseaMatricular = 's';
    while (deseaMatricular == 's' || deseaMatricular == 'S') {
        string codigoCurso;
        
        cout << "Ingrese el código del curso a matricular: ";
        cin >> codigoCurso;

        // Buscar el curso en la lista de cursos dentro de datosSistema
        auto itCurso = find_if(datosSistema.listaCursos.begin(), datosSistema.listaCursos.end(),
            [codigoCurso](const Curso& curso) {
                return curso.codigo == codigoCurso;
            });

        if (itCurso == datosSistema.listaCursos.end()) {
            cout << "Curso no encontrado. Verifique el código." << endl;
        } else {
            // Agregar el curso a la lista de matrícula del estudiante
            itEstudiante->listaMatricula.push_back(*itCurso);
            cout << "Estudiante matriculado en el curso correctamente." << endl;
        }

        // Preguntar si desea matricular al estudiante en otro curso
        cout << "¿Desea matricular al estudiante en otro curso? (s/n): ";
        cin >> deseaMatricular;

        if (deseaMatricular != 's' && deseaMatricular != 'S' && deseaMatricular != 'n' && deseaMatricular != 'N') {
            cout << "Respuesta no válida. Saliendo..." << endl;
            return;
        }
    }
}

// Función para verificar si un estudiante puede solicitar un componente
bool EstudiantePuedeSolicitarComponente(const Estudiante& estudiante, const string& codigoTipoComponente) {
    // Iterar sobre los cursos matriculados del estudiante
    for (const Curso& curso : estudiante.listaMatricula) {
        // Iterar sobre los proyectos de cada curso
        for (const Proyecto& proyecto : curso.listaProyectos) {
            // Verificar si el proyecto contiene el componente requerido
            for (const ComponenteRequerido& componenteRequerido : proyecto.compRequeridos) {
                const Componente& componente = componenteRequerido.tipoComponente;
                for (const Tipos& tipo : componente.tipos) {
                    if (tipo.codigo == codigoTipoComponente && tipo.cantidad > 0) {
                        // El estudiante puede solicitar el componente
                        return true;
                    }
                }
            }
        }
    }
    // El estudiante no puede solicitar el componente
    return false;
}

// Función para solicitar un componente a un estudiante
void SolicitarComponente(DatosSistema& datosSistema) {
    string carnet;
    string codigoTipoComponente;
    int cantidad;

    cout << "Ingrese el carnet del estudiante: ";
    cin >> carnet;

    // Buscar el estudiante en la lista de estudiantes
    auto itEstudiante = find_if(datosSistema.listaEstudiantes.begin(), datosSistema.listaEstudiantes.end(),
        [carnet](const Estudiante& estudiante) {
            return estudiante.carnet == carnet;
        });

    if (itEstudiante == datosSistema.listaEstudiantes.end()) {
        cout << "Estudiante no encontrado. Verifique el carnet." << endl;
        return;
    }

    cout << "Ingrese el código del tipo de componente que desea solicitar: ";
    cin >> codigoTipoComponente;

    // Verificar si el estudiante puede solicitar el componente
    if (EstudiantePuedeSolicitarComponente(*itEstudiante, codigoTipoComponente)) {
        // El estudiante puede solicitar el componente, procede a agregarlo a la lista de préstamos

        // Insertar el componente en la lista de préstamos del estudiante
        PrestamoTiposC prestamo;
        prestamo.tipoComponente.codigo = codigoTipoComponente;
        prestamo.proyecto = {}; // Aquí debes establecer el proyecto correspondiente
        prestamo.cantidad = cantidad; // Asegúrate de obtener la cantidad solicitada del usuario

        itEstudiante->listaPrestamos.push_back(prestamo);

        cout << "Componente solicitado correctamente." << endl;
    } else {
        // El estudiante no puede solicitar el componente, agrega a la lista de espera

        // Añadir el estudiante, el código del tipo de componente y la cantidad a la lista de espera
        // ... (debes implementar esta parte según la lógica de tu programa)
        cout << "El componente no está disponible para préstamo en ninguno de los cursos del estudiante." << endl;
    }
}


//Es el submenu de las inserciones permitidas
//Fecha de inicio: 14/9/2023
//Fecha última modificación: 20/9/2023.
void menuInserciones(){
    system("cls");
    int opcionInserciones;
    bool salirInserciones = false;
    while (salirInserciones!=true) {
        cout << "\n";
        cout << "-------- Menu de Inserciones --------" << endl;
        cout << "1. Ingresar Estudiante" << endl;
        cout << "2. Ingresar Curso" << endl;
        cout << "3. Ingresar Componente" << endl;
        cout << "4. Ingresar Proyecto" << endl;
        cout << "5. Pedir Componente" << endl;
        cout << "6. Regresar Componente" << endl;
        cout << "7. Ingresar Tipos" << endl;
        cout << "8. Matricular Estudiante." << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opcion:";
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
                cout << "Pedir Componente." << endl;
                //InsertarEstudianteListaEspera(datosSistema);
                SolicitarComponente(datosSistema);
                break;
            case 6:
                cout << "Regresar Componente." << endl;
                //InsertarListaMorosos(datosSistema);
                DevolverPrestamo(datosSistema);
                break;
            case 7:
                cout << "Insertar Tipo De Componente" << endl;
                InsertarTipo(datosSistema);
                break;
            case 8:
                cout << "Matricular Estudiante." << endl;
                MatricularEstudiante(datosSistema);
                break;
            case 9:
                salirInserciones = true;
                break;
            default:
                cout << "opcion no válida." << endl;
                break;
        }
    }
}

//Es el submenu de las ediciones permitidas
//Fecha de inicio: 14/9/2023
//Fecha última modificación: 20/9/2023.
void menuEdiciones(){
    int opcionEdicion;
    bool salirEdicion = false;
    while (salirEdicion!=true) {
        cout << "\n";
        cout << "-------- Menu de Ediciones --------" << endl;
        cout << "1. Editar Cursos" << endl;
        cout << "2. Editar Componentes" << endl;
        cout << "3. Volver al Menu Principal" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opcion:";
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
                cout << "opcion no válida." << endl;
                break;
        }
    }
}

void ConsultarListaMorosos(const ListaMorosos& listaMorosos) {
    cout << "=== Lista de Estudiantes Morosos ===" << endl;

    if (listaMorosos.estudiantes.empty()) {
        cout << "No hay estudiantes morosos en la lista." << endl;
    } else {
        // Iterar a través de la lista de morosos
        auto itEstudiante = listaMorosos.estudiantes.begin();
        auto itTipoComponente = listaMorosos.tiposComponentes.begin();
        auto itCantidadPendiente = listaMorosos.cantidadPendiente.begin();

        while (itEstudiante != listaMorosos.estudiantes.end() &&
               itTipoComponente != listaMorosos.tiposComponentes.end() &&
               itCantidadPendiente != listaMorosos.cantidadPendiente.end()) {
            // Mostrar información del estudiante moroso y la deuda
            cout << "Estudiante: " << itEstudiante->nombre << " " << itEstudiante->apellido << endl;
            cout << "Tipo de Componente: " << itTipoComponente->nombre << endl;
            cout << "Cantidad Pendiente: " << *itCantidadPendiente << endl;

            // Avanzar a la siguiente entrada en la lista
            ++itEstudiante;
            ++itTipoComponente;
            ++itCantidadPendiente;

            cout << "-----------------------------" << endl;
        }
    }
}

void MostrarListaEspera(const ListaEspera& listaEspera) {
    cout << "=== Lista de Estudiantes en Espera ===" << endl;

    if (listaEspera.estudiantes.empty()) {
        cout << "No hay estudiantes en espera en la lista." << endl;
    } else {
        auto itEstudiante = listaEspera.estudiantes.begin();
        auto itTipoComponente = listaEspera.tiposComponentes.begin();
        auto itCantidad = listaEspera.cantidad.begin();

        while (itEstudiante != listaEspera.estudiantes.end() &&
               itTipoComponente != listaEspera.tiposComponentes.end() &&
               itCantidad != listaEspera.cantidad.end()) {
            cout << "Estudiante: " << itEstudiante->nombre << " " << itEstudiante->apellido << endl;
            cout << "Tipo de Componente: " << itTipoComponente->nombre << endl;
            cout << "Cantidad en Espera: " << *itCantidad << endl;

            ++itEstudiante;
            ++itTipoComponente;
            ++itCantidad;

            cout << "-----------------------------" << endl;
        }
    }
}

void TresPrimerosTiposComponentesEscasez(){
    //auto itCurso = datosSistema.listaEstudiantes.listaMatricula.begin();
    //list<Proyecto> listaProyectos = *itCurso.listaProyectos;
    for (auto itEstudiante = datosSistema.listaEstudiantes.begin(); itEstudiante != datosSistema.listaEstudiantes.end(); ++itEstudiante) {
    cout << "Estudiante: " << itEstudiante->nombre << " " << itEstudiante->apellido << endl;
    
        for (auto itCurso = itEstudiante->listaMatricula.begin(); itCurso != itEstudiante->listaMatricula.end(); ++itCurso) {
            cout << "Curso: " << itCurso->nombre << endl;
            
            list<Proyecto> listaProyectos = itCurso->listaProyectos;
            for (const auto& proyecto : listaProyectos) {
                list<ComponenteRequerido> listaTiposComponenteRequerido = proyecto.compRequeridos;
                for(const auto& tipoComponenteRequerido : listaTiposComponenteRequerido){
                    cout << "TipoComponente: " << tipoComponenteRequerido.tipoComponente.nombre << "Cantidad: " << tipoComponenteRequerido.tipoComponente.cantidad <<", Cantidad min requerida: " << tipoComponenteRequerido.cantMinRequerida << endl;
                }
            }
        }
    }
}
/*
un curso tiene proyectos y un proyecto tiene componente requerido

de un curso obtenemos los componentes
<resistor,flipflop,condensador++,...> si el componente es repetido se suma

luego tenemos una lista global que hace lo mismo 

entonces tenemos una lista de todos los tipos de componentes que se requieren con su respectiva cantidad

luego cantidad requerida se resta con la cantidad oficial de componente

la lista resultado se ordena de menor a mayor*/


int SumarComponentesPorCarnet(const ListaMorosos& listaMorosos, const string& carnet) {
    int totalComponentes = 0;

    auto itEstudiante = listaMorosos.estudiantes.begin();
    auto itTipoComponente = listaMorosos.tiposComponentes.begin();
    auto itCantidadPendiente = listaMorosos.cantidadPendiente.begin();

    while (itEstudiante != listaMorosos.estudiantes.end() &&
           itTipoComponente != listaMorosos.tiposComponentes.end() &&
           itCantidadPendiente != listaMorosos.cantidadPendiente.end()) {
        if (itEstudiante->carnet == carnet) {
            totalComponentes += *itCantidadPendiente;
        }

        ++itEstudiante;
        ++itTipoComponente;
        ++itCantidadPendiente;
    }

    return totalComponentes;
}

int SumarComponentesPorCarnet2(const ListaEspera& listaEspera, const string& carnet) {
    int totalComponentes = 0;

    auto itEstudiante = listaEspera.estudiantes.begin();
    auto itTipoComponente = listaEspera.tiposComponentes.begin();
    auto itcantidad = listaEspera.cantidad.begin();

    while (itEstudiante != listaEspera.estudiantes.end() &&
           itTipoComponente != listaEspera.tiposComponentes.end() &&
           itcantidad != listaEspera.cantidad.end()) {
        if (itEstudiante->carnet == carnet) {
            totalComponentes += *itcantidad;
        }

        ++itEstudiante;
        ++itTipoComponente;
        ++itcantidad;
    }

    return totalComponentes;
}

bool verificarCarnetEstudiante(const ListaEspera& listaEspera, const string& carnet) {

    auto itEstudiante = listaEspera.estudiantes.begin();
    auto itTipoComponente = listaEspera.tiposComponentes.begin();
    auto itcantidad = listaEspera.cantidad.begin();

    while (itEstudiante != listaEspera.estudiantes.end() &&
           itTipoComponente != listaEspera.tiposComponentes.end() &&
           itcantidad != listaEspera.cantidad.end()) {
        if (itEstudiante->carnet == carnet) {
            return true;
        }

        ++itEstudiante;
        ++itTipoComponente;
        ++itcantidad;
    }
    return false;
}

void EstudiantesEsperaMasDeUnComponente(const ListaEspera& listaEspera) {
    unordered_map<string, int> contadorEstudiantes; 
    int maxApariciones = 0; 
    set<string> estudiantesRepetidos; 

    cout << "=== Estudiantes que esperan por mas de un tipo de componente ===" << endl;

    if (listaEspera.estudiantes.empty()) {
        cout << "No hay estudiantes en la lista de espera." << endl;
        return;
    } else {
        auto itEstudiante = listaEspera.estudiantes.begin();

        while (itEstudiante != listaEspera.estudiantes.end()) {
            // Incrementar el contador para este estudiante
            contadorEstudiantes[itEstudiante->carnet]++;

            // Actualizar el máximo de apariciones
            maxApariciones = max(maxApariciones, contadorEstudiantes[itEstudiante->carnet]);

            ++itEstudiante;
        }

        // Buscar a los estudiantes con el número máximo de apariciones
        for (const auto& entry : contadorEstudiantes) {
            if (entry.second == maxApariciones) {
                estudiantesRepetidos.insert(entry.first);
            }
        }
    }

    // Imprimir los estudiantes que aparecen mas veces
    cout << "Estudiantes que aparecen mas veces en la lista de espera y esperan por mas de un tipo de componente:" << endl;
    for (const auto& carnet : estudiantesRepetidos) {
        cout << "Carnet: " << carnet << " - Espera: " << maxApariciones << " componentes. " << endl;
    }
}



void EstudiantesConMasComponentesPrestados(const ListaEspera& listaEspera) {
    int maxCantidad = 0;
    list<Estudiante> estudiantesConMaxComponentes;

    cout << endl << "=== Estudiantes con mas tipos de componentes prestados ===" << endl;

    if (listaEspera.estudiantes.empty()) {
        cout << "No hay estudiantes con componentes prestados en la lista." << endl;
        return;
    } else {
        auto itEstudiante = listaEspera.estudiantes.begin();
        auto itTipoComponente = listaEspera.tiposComponentes.begin();
        auto itcantidad = listaEspera.cantidad.begin();

        while (itEstudiante != listaEspera.estudiantes.end() &&
               itTipoComponente != listaEspera.tiposComponentes.end() &&
               itcantidad != listaEspera.cantidad.end()) {
            int cantidadEst = SumarComponentesPorCarnet2(listaEspera, itEstudiante->carnet);
            if (cantidadEst > maxCantidad) {
                maxCantidad = cantidadEst;
                estudiantesConMaxComponentes.clear();  // Limpiar la lista si encontramos una cantidad mayor
                estudiantesConMaxComponentes.push_back(*itEstudiante);
            } else if (cantidadEst == maxCantidad) {
                if(!verificarCarnetEstudiante(listaEspera, itEstudiante->carnet)){
                    estudiantesConMaxComponentes.push_back(*itEstudiante);  // Agregar a la lista de estudiantes con la misma cantidad
                }
            }
            ++itEstudiante;
            ++itTipoComponente;
            ++itcantidad;
        }
    }
    cout << "Los estudiantes con mayor componentes prestados son: " << endl;
    for (const auto& estudiante : estudiantesConMaxComponentes) {
        cout << "Nombre: " << estudiante.nombre << " Carnet: " << estudiante.carnet << " Cantidad TOTAL pendiente: " << maxCantidad << endl;
    }
}

// Función para encontrar al estudiante con la mayor morosidad
void EstudianteConMayorMorosidad(const ListaMorosos& listaMorosos) {
    int maxCantidad = 0;
    int cantidadEst = 0;
    Estudiante estudiante;
    cout << endl<< "=== Estudiantes mas Moroso ===" << endl;
    if (listaMorosos.estudiantes.empty()) {
        cout << "No hay estudiantes morosos en la lista." << endl;
        return;
    }else {
        // Iterar a través de la lista de morosos
        auto itEstudiante = listaMorosos.estudiantes.begin();
        auto itTipoComponente = listaMorosos.tiposComponentes.begin();
        auto itCantidadPendiente = listaMorosos.cantidadPendiente.begin();
        while (itEstudiante != listaMorosos.estudiantes.end() &&
               itTipoComponente != listaMorosos.tiposComponentes.end() &&
               itCantidadPendiente != listaMorosos.cantidadPendiente.end()) {
            cantidadEst = SumarComponentesPorCarnet(listaMorosos,itEstudiante->carnet);
            if(cantidadEst>maxCantidad){
                maxCantidad = cantidadEst;
                estudiante = *itEstudiante;
            }
            ++itEstudiante;
            ++itTipoComponente;
            ++itCantidadPendiente;
        }
    }
    cout << "El estudiante con mayor morosidad es: " << endl;
    cout << "Nombre: "<<estudiante.nombre <<" Carnet: "<< estudiante.carnet << " Cantidad TOTAL pendiente: " << maxCantidad<< endl;
    return;
}





////Es el submenu de las consulas que puede realizar el usuario
//Fecha de inicio: 14/9/2023
//Fecha última modificación: 20/9/2023.
void consultas(){
    system("cls");
    int opcionConsulta;
    bool salirConsutla = false;
    while (salirConsutla!=true) {
        cout << "\n";
        cout << "-------- Menu de Consultas --------" << endl;
        cout << "1. Curso que requiere mas componentes electronicos en general" << endl;
        cout << "2. Estudiante con mas proyectos asignados" << endl;
        cout << "3. Proyecto que requiere mas tipos de componentes" << endl;
        cout << "4. Estudiantes que deben esperar por mas de un tipo de componente" << endl;
        cout << "5. Primeros tres tipos de componente requeridos por escasez" << endl;
        cout << "6. Estudiante con mas tipos de componente prestados" << endl;
        cout << "7. Estudiante con mayor morosidad" << endl;
        cout << "8. Lista de morosos" << endl;
        cout << "9. Lista de espera." << endl;
        cout << "10. Volver al Menu Principal" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opcion:";
        cin >> opcionConsulta;
        switch(opcionConsulta){
            case 1:
                cout << "1. Curso que requiere mas componentes electronicos en general" << endl;
                cursoReqMasComponentes();
                break;
            case 2:
                cout << "2. Estudiante con mas proyectos asignados" << endl;
                estuConMasProyectos();
                break;
            case 3:
                cout << "3. Proyecto que requiere mas tipos de componentes" << endl;
                proyectoConMasTiposComponentes();
                break;
            case 4:
                cout << "4. Estudiantes que deben esperar por mas de un tipo de componente" << endl;
                EstudiantesEsperaMasDeUnComponente(datosSistema.listaEspera);
                break;
            case 5:
                cout << "5. Primeros tres tipos de componente requeridos por escasez" << endl;
                TresPrimerosTiposComponentesEscasez();
                break;
            case 6:
                cout << "6. Estudiante con mas tipos de componente prestados" << endl;
                EstudiantesConMasComponentesPrestados(datosSistema.listaEspera);
                break;
            case 7:
                cout << "7. Estudiante con mayor morosidad" << endl;
                EstudianteConMayorMorosidad(datosSistema.listaMorosos);
                break;
            case 8:
                cout << "8. Lista de estudiantes morosos" << endl;
                ConsultarListaMorosos(datosSistema.listaMorosos);
                break;
            case 9:
                cout << "9. Lista de espera." << endl;
                MostrarListaEspera(datosSistema.listaEspera);
                break;
            case 10:
                salirConsutla = true;
                break;
            default:
                cout << "opcion no válida." << endl;
                break;
        }
    }
}

//Funcion que genera el primer reporte: informacion de todas las listas con sublistas respectivas
//Fecha de inicio: 20/9/2023
//Fecha última modificación: 22/9/2023.
void GenerarReporte() {
    // Imprime la información de la lista de estudiantes
    cout << "=== Lista de Estudiantes ===" << endl;
    for (auto& estudiante : datosSistema.listaEstudiantes) {
        cout << estudiante.ToString() << "\n\n";
    }

    // Imprime la información de la lista de cursos
    cout << "=== Lista de Cursos ===" << endl;
    for ( auto& curso : datosSistema.listaCursos) {
        cout << curso.ToString() << "\n\n";
    }

    // Imprime la información de la lista de componentes
    cout << "=== Lista de Componentes ===" << endl;
    for ( auto& componente : datosSistema.listaComponentes) {
        cout << componente.ToString() << "\n\n";
    }

    // Imprime la información de la lista de proyectos
    cout << "=== Lista de Proyectos ===" << endl;
    for ( auto& proyecto : datosSistema.listaProyectos) {
        cout << proyecto.ToString() << "\n\n";
    }

    // Imprime la información de la lista de tipos
    cout << "=== Lista de Tipos ===" << endl;
    for ( auto& tipo : datosSistema.listaTipos) {
        cout << tipo.ToString() << "\n\n";
    }

    // Imprime la información de la lista de espera
    cout << "=== Lista de Espera ===" << endl;
    cout << datosSistema.listaEspera.ToString() << "\n\n";

    // Imprime la información de la lista de morosos
    cout << "=== Lista de Morosos ===" << endl;
    cout << datosSistema.listaMorosos.ToString() << "\n\n";
}

//Funcion que permite generar el segundo reporte: imprimir estudiantes sin matricula
//Fecha de inicio: 20/9/2023
//Fecha última modificación: 22/9/2023.
void GenerarReporteEstudiantesSinMatricula() {
    cout << "=== Estudiantes sin Matrícula ===" << endl;
    
    bool hayEstudiantesSinMatricula = false;

    for (auto& estudiante : datosSistema.listaEstudiantes) {
        if (estudiante.listaMatricula.empty()) {
            cout << estudiante.ToString() << "\n\n";
    

            hayEstudiantesSinMatricula = true;
        }
    }

    if (!hayEstudiantesSinMatricula) {
        cout << "No hay estudiantes sin matrícula." << endl;
    }
}

//Funcion que permite generar el tercer reporte: estudiantes sin prestamos
//Fecha de inicio: 20/9/2023
//Fecha última modificación: 22/9/2023.
void GenerarReporteEstudiantesSinPrestamos() {
    cout << "***Estudiantes sin Préstamos***" << endl;

    for (auto& estudiante : datosSistema.listaEstudiantes) {
        if (estudiante.listaPrestamos.size() <= 0){
            cout <<"Nombre: " << estudiante.nombre <<" " << estudiante.apellido <<"\n";
            cout <<"Cédula: "<< estudiante.cedula << "\n";
            cout <<"Carné: "<< estudiante.carnet << "\n\n";
        }
    }

}

//Funcion que permite generar el cuarto repore: tipos de componentes con cantidad 0
//Fecha de inicio: 21/9/2023
//Fecha última modificación: 22/9/2023.
void CompCantCero(const DatosSistema& datosSistema) {
    cout << "=== Componentes con Tipos de Cantidad Cero ===" << endl;

    for (const Componente& componente : datosSistema.listaComponentes) {
        bool tieneTipoConCantidadCero = false;

        // Verificar si alguno de los tipos del componente tiene cantidad igual a 0
        for (const Tipos& tipo : componente.tipos) {
            if (tipo.cantidad == 0) {
                tieneTipoConCantidadCero = true;
                break;
            }
        }

        if (tieneTipoConCantidadCero) {
            cout << "Componente: " << componente.nombre << endl;
            cout << "Tipos:" << endl;

            for (const Tipos& tipo : componente.tipos) {
                if (tipo.cantidad == 0) {
                    cout << tipo.nombre << endl;
                    cout << "Cantidad: " << tipo.cantidad << endl;
                }
            }

            cout << "=================================" << endl;
        }
    }
}

void EliminarEstudiante(DatosSistema& datosSistema, const string& carnet) {
    // Buscar el estudiante en la lista de estudiantes
    auto itEstudiante = find_if(datosSistema.listaEstudiantes.begin(), datosSistema.listaEstudiantes.end(),
        [carnet](const Estudiante& estudiante) {
            return estudiante.carnet == carnet;
        });

    if (itEstudiante != datosSistema.listaEstudiantes.end()) {
        // Eliminar el estudiante de la lista
        datosSistema.listaEstudiantes.erase(itEstudiante);
        cout << "Estudiante eliminado correctamente." << endl;
    } else {
        cout << "Estudiante no encontrado. Verifique el carnet." << endl;
    }
}


//Submenu que permite al usuario seleccionar un reporte a desplegar
//Fecha de inicio: 216/9/2023
//Fecha última modificación: 22/9/2023.
void reportes(){
    system("cls");
    int opcionReporte;
    bool salirReporte = false;
    while (salirReporte!=true) {
        cout << "\n";
        cout << "-------- Menu de Reportes --------" << endl;
        cout << "1. Información de todas las listas" << endl;
        cout << "2. Estudiantes sin matricula" << endl;
        cout << "3. Estudiantes sin préstamos" << endl;
        cout << "4. Tipos de componentes con cantidad 0." << endl;
        cout << "5. Volver al Menu Principal" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opcion:";
        cin >> opcionReporte;
        switch(opcionReporte){
            case 1:
                cout << "1. Información de todas las listas" << endl;
                GenerarReporte();
                break;
            case 2:
                cout << "2. Estudiantes sin matricula" << endl;
                GenerarReporteEstudiantesSinMatricula();
                break;
            case 3:
                cout << "3. Estudiantes sin préstamos" << endl;
                GenerarReporteEstudiantesSinPrestamos();
                break;
            case 4:
                cout << "4. Tipos de componentes con cantidad 0." << endl;
                CompCantCero(datosSistema);
                break;
            case 5:
                salirReporte = true;
                break;
            default:
                cout << "opcion no válida." << endl;
                break;
        }
    }
}

//Menu principal del sistema con las opciones para insertar datos, modifica, eliminar, realizar consulas o ver reportes
//Fecha de inicio: 16/9/2023
//Fecha última modificación: 22/9/2023.
void menu(){
    system("cls");
    agregarDatosAlDatosSistema();
    int opcionMenu;
    bool salir=false;
    string crne;
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
                //menuEdiciones();
                break;
            case 3:
                cout << "Ingrese el carnet del estudiante a borrar: ";
                cin >> crne;
                EliminarEstudiante(datosSistema, crne);
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

//Main del programa, llama a Menu() que es la funcion del menú principal en donde se ejecuta el resto de lógica de submenus.
int main() {
    system("cls");
    menu();
    return 0;
}
