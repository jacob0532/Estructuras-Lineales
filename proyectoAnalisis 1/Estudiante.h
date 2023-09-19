#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

using namespace std;

struct Estudiante {
    string carnet;
    string nombre;
    string apellido;
    string cedula;
    int edad;
    string lugarResidencia;

    Estudiante() = default;
    Estudiante(string carnet, string nombre, string apellido, string cedula, int edad, string lugarResidencia);
    // Método para obtener una representación en string del estudiante
    string ToString();
};

#endif  // ESTUDIANTE_H

