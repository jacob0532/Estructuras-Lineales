#include "Curso.h"    //se incluyen las librerías neceasarias 
#include <iostream>

using namespace std;

//Constructor de la clase
Curso::Curso(string codigo, string nombre, int creditos, list<Proyecto> listaProyectos)
    : codigo(codigo), nombre(nombre), creditos(creditos), listaProyectos(listaProyectos) {
}

// Método que permite obtener una representación en string del curso
string Curso::ToString() const{
    string cursoString = "Codigo: " + codigo + "\n";
    cursoString += "Nombre: " + nombre + "\n";
    cursoString += "Creditos: " + to_string(creditos) + "\n";

    cursoString += "Lista de Proyectos:\n";
    for (const Proyecto& proyecto : listaProyectos) {
        cursoString += " - Nombre del Proyecto: " + proyecto.nombre + "\n";

    }

    return cursoString;
}