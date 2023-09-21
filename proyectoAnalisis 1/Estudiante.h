#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

using namespace std;

class Estudiante {
public:
    string carnet;
    string nombre;
    string apellido;
    string cedula;
    int edad;
    string lugarResidencia;

public:
    Estudiante() = default;
    Estudiante(string carnet, string nombre, string apellido, string cedula, int edad, string lugarResidencia);
    
    // Método para obtener una representación en string del estudiante
    string ToString();
};

#endif  // ESTUDIANTE_H


