#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <list>

using namespace std;

// Definición del struct PrestamoTiposC
struct PrestamoTiposC {
    // Atributos del struct PrestamoTiposC
    Componente tipoComponente;
    Proyecto proyecto
    int cantidad;
};

class Estudiante {
public:
    string carnet;
    string nombre;
    string apellido;
    string cedula;
    int edad;
    string lugarResidencia;
    list<Curso> listaMatricula;
    lista<PrestamoTiposC> listaPrestamos;

public:
    Estudiante() = default;
    Estudiante(string carnet, string nombre, string apellido, string cedula, int edad, string lugarResidencia);
    
    // Método para obtener una representación en string del estudiante
    string ToString();
};

#endif  // ESTUDIANTE_H



