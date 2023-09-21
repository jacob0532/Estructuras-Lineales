#ifndef TIPOCOMPONENTE_H
#define TIPOCOMPONENTE_H

#include <string>

using namespace std;

class TipoComponente {
public:
    string codigo;
    string nombre;
    string descripcion;
    string dondeSeUtilizan;
    int cantidad;

public:
    TipoComponente() = default;
    TipoComponente(string codigo, string nombre, string descripcion, string dondeSeUtilizan, int cantidad);
    
    // Método para obtener una representación en string del tipo de componente
    string ToString();
};

#endif  // TIPOCOMPONENTE_H


