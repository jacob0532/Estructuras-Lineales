#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>

using namespace std;

struct Proyecto {
    string nombre;
    string descripcion;
    double valorPorcentual;

    // Método para obtener una representación en string del proyecto
    string ToString();
};

#endif  // PROYECTO_H

