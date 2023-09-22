#ifndef CURSO_H
#define CURSO_H

#include "Proyecto.h"
#include <string>
#include <list>

using namespace std;

/*
Fecha de inicio: 13/9/2023
Fecha última modificación: 13/9/2023 .
Descripción para cada estructura (clase) y su uso en el programa,
Describir cada función e instrucciones dentro de estas.*/
class Curso {
public:
    string codigo;
    string nombre;
    int creditos;
    list<Proyecto> listaProyectos;

public:
    Curso() = default;
    Curso(string codigo, string nombre, int creditos, list<Proyecto> listaProyectos);
    
    // Método para obtener una representación en string del curso
    string ToString() const;
};

#endif  // CURSO_H


