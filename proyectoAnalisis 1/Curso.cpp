#include "Curso.h"
#include <iostream>

using namespace std;


Curso::Curso(string codigo, string nombre, int creditos)
    : codigo(codigo), nombre(nombre), creditos(creditos) {}
// Método para obtener una representación en string del curso
string Curso::ToString() {
    string info = "Código: " + codigo + "\n";
    info += "Nombre: " + nombre + "\n";
    info += "Créditos: " + to_string(creditos) + "\n";

    return info;
}
