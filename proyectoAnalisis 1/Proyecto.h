#ifndef PROYECTO_H
#define PROYECTO_H

#include "Componente.h"
#include <string>

using namespace std;

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
    list<ComponenteRequerido> ComponentesRequeridos;

public:
    Proyecto() = default;
    Proyecto(string nombre, string descripcion, double valorPorcentual);
    
    // Método para obtener una representación en string del proyecto
    string ToString() const;
};

#endif  // PROYECTO_H

