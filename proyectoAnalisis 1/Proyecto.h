#ifndef PROYECTO_H
#define PROYECTO_H

#include "Componente.h"
#include <string>

using namespace std;

/*
Fecha de inicio: 15/9/2023
Fecha última modificación: 15/9/2023 .
Descripción para cada estructura (clase) y su uso en el programa,
Describir cada función e instrucciones dentro de estas.*/
// Definición del struct ComponenteRequerido
struct ComponenteRequerido {
    // Atributos del struct ComponenteRequerido
    Componente tipoComponente;
    int cantMinRequerida;
};

class Proyecto {
public:
    string nombre;
    string descripcion;
    double valorPorcentual;
    list<ComponenteRequerido> compRequeridos;

public:
    Proyecto() = default;
    Proyecto(string nombre, string descripcion, double valorPorcentual);
    
    // Método para obtener una representación en string del proyecto
    string ToString() const;
};

#endif  // PROYECTO_H

