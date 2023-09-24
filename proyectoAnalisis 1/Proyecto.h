#ifndef PROYECTO_H
#define PROYECTO_H

#include "Componente.h"
#include "Tipos.h"
#include <string>

using namespace std;

/*
Fecha de inicio: 15/9/2023
Fecha última modificación: 20/9/2023 .
la clase Proyecto representa los proyectos
que tienen los cursos dentro del programa.
*/

// Definición del struct ComponenteRequerido
struct ComponenteRequerido {
    // Atributos del struct ComponenteRequerido
    Tipos tipoComponente;
    int cantMinRequerida;
};

//Se definen los atributos que utiliza la clase Componente
class Proyecto {
public:
    string nombre;
    string descripcion;
    double valorPorcentual;
    list<ComponenteRequerido> compRequeridos;

public:
    Proyecto() = default;
    Proyecto(string nombre, string descripcion, double valorPorcentual); //constructor de la clas ListaMorosos
    
    // Método para obtener una representación en string del proyecto
    string ToString() const;
};

#endif  // PROYECTO_H

