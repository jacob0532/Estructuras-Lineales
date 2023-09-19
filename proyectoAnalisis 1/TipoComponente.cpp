#include "TipoComponente.h"
#include <iostream>

using namespace std;



// Método para obtener una representación en string del tipo de componente
string TipoComponente::ToString() {
    string info = "Código: " + codigo + "\n";
    info += "Nombre: " + nombre + "\n";
    info += "Descripción: " + descripcion + "\n";
    info += "Donde se utilizan: " + dondeSeUtilizan + "\n";
    info += "Cantidad: " + to_string(cantidad) + "\n";

    return info;
}
