#ifndef TIPOCOMPONENTE_H
#define TIPOCOMPONENTE_H

#include <string>

struct TipoComponente {
    std::string codigo;
    std::string nombre;
    std::string descripcion;
    std::string dondeSeUtilizan;
    int cantidad;

    // Método para obtener una representación en string del tipo de componente
    std::string ToString();
};

#endif  // TIPOCOMPONENTE_H

