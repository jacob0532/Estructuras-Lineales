#include "Componente.h"
#include <iostream>

using namespace std;

Componente::Componente(string codigo, string nombre, string descripcion, Clasificacion clasificacion, string aplicaciones)
    : codigo(codigo), nombre(nombre), descripcion(descripcion), clasificacion(clasificacion), aplicaciones(aplicaciones) {
}

// Método para obtener una representación en string del componente
string Componente::ToString() {
    string componenteString = "Código: " + codigo + "\n";
    componenteString += "Nombre: " + nombre + "\n";
    componenteString += "Descripción: " + descripcion + "\n";

    // Convertir la clasificación a string
    string clasificacionStr;
    if (clasificacion == ACTIVO) {
        clasificacionStr = "Activo";
    } else {
        clasificacionStr = "Pasivo";
    }
    componenteString += "Clasificación: " + clasificacionStr + "\n";

    componenteString += "Aplicaciones: " + aplicaciones + "\n";

    // Agregar lógica para convertir la lista de Tipos a string si es necesario

    return componenteString;
}
