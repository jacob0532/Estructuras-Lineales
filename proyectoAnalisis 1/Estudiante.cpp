#include "Estudiante.h"
#include <iostream>

using namespace std;

Estudiante::Estudiante(string carnet, string nombre, string apellido, string cedula, int edad, string lugarResidencia)
    : carnet(carnet), nombre(nombre), apellido(apellido), cedula(cedula), edad(edad), lugarResidencia(lugarResidencia) {}

string Estudiante::ToString() {
    string info = "Carnet: " + carnet + "\n";
    info += "Nombre: " + nombre + "\n";
    info += "Apellido: " + apellido + "\n";
    info += "Cedula: " + cedula + "\n";
    info += "Edad: " + to_string(edad) + "\n";
    info += "Lugar de Residencia: " + lugarResidencia + "\n";

    // Convertir lista de matrículas a string
    info += "Lista de Matrículas:\n";
    for (const Curso& curso : listaMatricula) {
        info += "\t" + curso.ToString() + "\n";
    }

    // Convertir lista de préstamos a string
    info += "Lista de Préstamos:\n";
    for (const PrestamoTiposC& prestamo : listaPrestamos) {
        info += "\tTipo de Componente: " + prestamo.tipoComponente.ToString() + "\n";
        info += "\tProyecto: " + prestamo.proyecto.ToString() + "\n";
        info += "\tCantidad: " + to_string(prestamo.cantidad) + "\n";
    }

    return info;
}

