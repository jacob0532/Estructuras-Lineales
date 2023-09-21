#include "Proyecto.h"
#include <iostream>

using namespace std;



Proyecto::Proyecto(string nombre, string descripcion, double valorPorcentual)
    : nombre(nombre), descripcion(descripcion), valorPorcentual(valorPorcentual) {
}

// Método para obtener una representación en string del proyecto
string Proyecto::ToString() {
    string proyectoString = "Nombre: " + nombre + "\n";
    proyectoString += "Descripción: " + descripcion + "\n";
    proyectoString += "Valor Porcentual: " + to_string(valorPorcentual) + "\n";

    proyectoString += "Componentes Requeridos:\n";
    for (const ComponenteRequerido& componente : ComponentesRequeridos) {
        proyectoString += " - Tipo de Componente: " + componente.tipoComponente + "\n";
        proyectoString += "   Cantidad Mínima Requerida: " + to_string(componente.cantMinRequerida) + "\n";
        // Agregar otros atributos relevantes de la clase ComponenteRequerido si es necesario
    }

    return proyectoString;
}
