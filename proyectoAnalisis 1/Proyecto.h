#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>

using namespace std;

class Proyecto {
public:
    string nombre;
    string descripcion;
    double valorPorcentual;

public:
    Proyecto() = default;
    Proyecto(string nombre, string descripcion, double valorPorcentual);
    
    // Método para obtener una representación en string del proyecto
    string ToString();
};

#endif  // PROYECTO_H

