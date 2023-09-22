#ifndef CURSO_H
#define CURSO_H

#include "Proyecto.h"
#include <string>
#include <list>

using namespace std;

/*
Fecha de inicio: 13/9/2023
Fecha última modificación: 13/9/2023 .
Esta clase representa los cursos dentro del sistema.
*/

//se definen los atributos de la clase
class Curso {
public:
    string codigo;
    string nombre;
    int creditos;
    list<Proyecto> listaProyectos;

//se declaran los metodos y el constructor
public:
    Curso() = default;
    Curso(string codigo, string nombre, int creditos, list<Proyecto> listaProyectos);//constructor
    
    // Método que permie obtener una representación en string del curso
    string ToString() const;
};

#endif  // CURSO_H


