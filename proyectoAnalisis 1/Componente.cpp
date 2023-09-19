#include "Componente.h"
#include <iostream>

using namespace std;

Componente::Componente(string codigo, string nombre, string descripcion, string clasificacion, string aplicaciones)
    : codigo(codigo), nombre(nombre), descripcion(descripcion), clasificacion(clasificacion), aplicaciones(aplicaciones) {}
// Método para obtener una representación en string del componente
string Componente::ToString() {
    string info = "Código: " + codigo + "\n";
    info += "Nombre: " + nombre + "\n";
    info += "Descripción: " + descripcion + "\n";
    info += "Clasificación: " + clasificacion + "\n";
    info += "Aplicaciones: " + aplicaciones + "\n";

    return info;
}
