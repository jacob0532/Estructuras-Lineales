#ifndef COMPONENTE_H
#define COMPONENTE_H

#include "Tipos.h"

#include <string>
#include <list>

using namespace std;

// Definición del enumerado para la clasificación
enum Clasificacion {
    ACTIVO,
    PASIVO
};

class Componente {
public:
    string codigo;
    string nombre;
    string descripcion;
    Clasificacion clasificacion; // Utilizamos el enumerado Clasificacion
    string aplicaciones;
    list<Tipos> tipos; // Cambiamos el nombre de la lista a "tipos"

public:
    Componente() = default;
    Componente(string codigo, string nombre, string descripcion, Clasificacion clasificacion, string aplicaciones);
    
    // Método para obtener una representación en string del componente
    string ToString() const;
};

#endif  // COMPONENTE_H


