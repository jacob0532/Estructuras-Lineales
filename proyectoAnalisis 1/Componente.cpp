#include "Componente.h"   //se incluyen las librerías neceasarias 
#include <iostream>

using namespace std;

//Constructor de la clase Componente
Componente::Componente(string codigo, string nombre, string descripcion, Clasificacion clasificacion, string aplicaciones)
    : codigo(codigo), nombre(nombre), descripcion(descripcion), clasificacion(clasificacion), aplicaciones(aplicaciones) {
}

// Método que permite obtener una representación en string del componente para facilitar su impresion.
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
    //retorna la informacion como un solo string
    return componenteString;
}
