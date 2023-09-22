#include "Curso.h"
#include <iostream>

using namespace std;


Curso::Curso(string codigo, string nombre, int creditos, list<Proyecto> listaProyectos)
    : codigo(codigo), nombre(nombre), creditos(creditos), listaProyectos(listaProyectos) {
}

// Método para obtener una representación en string del curso
string Curso::ToString() const{
    string cursoString = "Código: " + codigo + "\n";
    cursoString += "Nombre: " + nombre + "\n";
    cursoString += "Créditos: " + to_string(creditos) + "\n";

    cursoString += "Lista de Proyectos:\n";
    for (const Proyecto& proyecto : listaProyectos) {
        cursoString += " - Nombre del Proyecto: " + proyecto.nombre + "\n";
        // Agregar otros atributos relevantes de la clase Proyecto según sea necesario
    }

    return cursoString;
}