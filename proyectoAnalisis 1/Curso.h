#ifndef CURSO_H
#define CURSO_H

#include <string>

using namespace std;

struct Curso {
    string codigo;
    string nombre;
    int creditos;

    Curso() = default;


    // Constructor con argumentos
    Curso(string codigo, string nombre, int creditos);
    // Método para obtener una representación en string del curso
    string ToString();
};

#endif  // CURSO_H

