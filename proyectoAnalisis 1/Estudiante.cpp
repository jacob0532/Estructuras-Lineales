#include "Estudiante.h"
#include <iostream>

using namespace std;


Estudiante::Estudiante(string carnet, string nombre, string apellido, string cedula, int edad, string lugarResidencia)
    : carnet(carnet), nombre(nombre), apellido(apellido), cedula(cedula), edad(edad), lugarResidencia(lugarResidencia) {}
    
// Método para obtener una representación en string del estudiante
string Estudiante::ToString() {
    string info = "Carnet: " + carnet + "\n";
    info += "Nombre: " + nombre + "\n";
    info += "Apellido: " + apellido + "\n";
    info += "Cédula: " + cedula + "\n";
    info += "Edad: " + to_string(edad) + "\n";
    info += "Lugar de Residencia: " + lugarResidencia + "\n";

    return info;
}
