#include "Componente.h"
#include <iostream>

using namespace std;

Componente::Componente(string codigo, string nombre, string descripcion, Clasificacion clasificacion, string aplicaciones)
    : codigo(codigo), nombre(nombre), descripcion(descripcion), clasificacion(clasificacion), aplicaciones(aplicaciones) {
}

// Método para obtener una representación en string del componente
string Componente::ToString() const{
    string componenteString = "Codigo: " + codigo + "\n";
    componenteString += "Nombre: " + nombre + "\n";
    componenteString += "Descripcion: " + descripcion + "\n";

    // Convertir la clasificación a string
    string clasificacionStr;
    if (clasificacion == ACTIVO) {
        clasificacionStr = "Activo";
    } else {
        clasificacionStr = "Pasivo";
    }
    componenteString += "Clasificacion: " + clasificacionStr + "\n";

    componenteString += "Aplicaciones: " + aplicaciones + "\n";

    componenteString += "Tipos:\n";
    for (auto& tipo : tipos) {
        componenteString += "\tCodigo: " + tipo.codigo + "\n";
        componenteString += "\tNombre: " + tipo.nombre + "\n";
        componenteString += "\tDescripcion: " + tipo.descripcion + "\n";
        componenteString += "\tDonde se utilizan: " + tipo.dondeSeUtilizan + "\n";
        componenteString += "\tCantidad: " + to_string(tipo.cantidad) + "\n";
        componenteString += "\n";
    }

    return componenteString;
}
