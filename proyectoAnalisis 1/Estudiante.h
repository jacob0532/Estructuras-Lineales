#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Curso.h"
#include "Componente.h"
#include "Proyecto.h"
#include <string>
#include <list>
#include "Tipos.h"

using namespace std;
/*
Fecha de inicio: 13/9/2023
Fecha última modificación: 19/9/2023 .
Esta clase representa a los estudiantes dentro del programa
*/

// Definición del struct PrestamoTiposC
struct PrestamoTiposC {
    // Atributos del struct 
    Tipos tipoComponente;
    Proyecto proyecto;
    int cantidad;
};

//Atributos de la clase Estudiante
class Estudiante {
public:
    string carnet;
    string nombre;
    string apellido;
    string cedula;
    int edad;
    string lugarResidencia;
    list<Curso> listaMatricula;
    list<PrestamoTiposC> listaPrestamos;

public:
    Estudiante() = default;
    Estudiante(string carnet, string nombre, string apellido, string cedula, int edad, string lugarResidencia); //constructor de la clase Estudiante
    
    // Método permite obtener una representación en string del estudiante
    string ToString() const;
    //Método que permite al estudiante solicitar un prestamo
    bool SolicitarPrestamo(Componente tipoComponente, int cantidad);
};

#endif  // ESTUDIANTE_H



