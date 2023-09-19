#include "Proyecto.h"
#include <iostream>

using namespace std;



// Método para obtener una representación en string del proyecto
string Proyecto::ToString() {
    string info = "Nombre: " + nombre + "\n";
    info += "Descripción: " + descripcion + "\n";
    info += "Valor porcentual: " + to_string(valorPorcentual) + "\n";

    return info;
}
