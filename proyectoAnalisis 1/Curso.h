#ifndef CURSO_H
#define CURSO_H

#include <string>

using namespace std;

class Curso {
public:
    string codigo;
    string nombre;
    int creditos;

public:
    Curso() = default;
    Curso(string codigo, string nombre, int creditos);
    
    // Método para obtener una representación en string del curso
    string ToString();
};

#endif  // CURSO_H


