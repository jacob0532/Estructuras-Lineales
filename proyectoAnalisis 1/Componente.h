#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <string>

using namespace std;

class Componente {
public:
    string codigo;
    string nombre;
    string descripcion;
    string clasificacion; // Activo o Pasivo
    string aplicaciones;

public:
    Componente() = default;
    Componente(string codigo, string nombre, string descripcion, string clasificacion, string aplicaciones);
    
    // Método para obtener una representación en string del componente
    string ToString();
};

#endif  // COMPONENTE_H


