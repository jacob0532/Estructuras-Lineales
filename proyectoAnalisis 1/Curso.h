#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <list>

using namespace std;

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
    string ToString();
};

#endif  // CURSO_H


