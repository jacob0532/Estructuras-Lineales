#include "Tipos.h"   //se incluyen las librerías neceasarias
#include <iostream>

using namespace std;


//Constructor de la clase Tipos
Tipos::Tipos(string codigo, string nombre, string descripcion, string dondeSeUtilizan, int cantidad)
    : codigo(codigo), nombre(nombre), descripcion(descripcion), dondeSeUtilizan(dondeSeUtilizan), cantidad(cantidad) {
}

// Método que permite obtener una representación en string del tipo de componente
string Tipos::ToString() const{
    string tipoString = "Codigo: " + codigo + "\n";
    tipoString += "Nombre: " + nombre + "\n";
    tipoString += "Descripcion: " + descripcion + "\n";
    tipoString += "Donde se utilizan: " + dondeSeUtilizan + "\n";
    tipoString += "Cantidad: " + to_string(cantidad) + "\n";

    return tipoString;
}
