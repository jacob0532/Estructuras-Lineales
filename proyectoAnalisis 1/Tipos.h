#ifndef Tipos_H
#define Tipos_H

#include <string>

using namespace std;

class Tipos {
public:
    string codigo;
    string nombre;
    string descripcion;
    string dondeSeUtilizan;
    int cantidad;

public:
    Tipos() = default;
    Tipos(string codigo, string nombre, string descripcion, string dondeSeUtilizan, int cantidad);
    
    // Método para obtener una representación en string del tipo de componente
    string ToString();
};

#endif  // Tipos_H


