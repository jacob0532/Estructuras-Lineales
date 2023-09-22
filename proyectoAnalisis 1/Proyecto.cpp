#include "Proyecto.h"  //se incluyen las librerías neceasarias
#include <iostream>

using namespace std;


//Constructor de la clase Proyecto
Proyecto::Proyecto(string nombre, string descripcion, double valorPorcentual)
    : nombre(nombre), descripcion(descripcion), valorPorcentual(valorPorcentual) {
}

// Método que permite obtener una representación en string del proyecto
string Proyecto::ToString() const{
    string proyectoString = "Nombre: " + nombre + "\n";
    proyectoString += "Descripcion: " + descripcion + "\n";
    proyectoString += "Valor Porcentual: " + to_string(valorPorcentual) + "\n";

    proyectoString += "Componentes Requeridos:\n";
    for (const ComponenteRequerido& componente : compRequeridos) {
        proyectoString += " - Tipo de Componente: " + componente.tipoComponente.ToString() + "\n";
        proyectoString += "   Cantidad Minima Requerida: " + to_string(componente.cantMinRequerida) + "\n";
        // Agregar otros atributos relevantes de la clase ComponenteRequerido si es necesario
    }

    return proyectoString;
}


