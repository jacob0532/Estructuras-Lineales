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

bool Estudiante::SolicitarPrestamo(Componente tipoComponente, int cantidad) {
    // Itera sobre los cursos matriculados del estudiante
    for (const Curso& curso : listaMatricula) {
        // Busca el proyecto asociado a este curso
        for (const Proyecto& proyecto : curso.listaProyectos) {
            // Verifica si el tipo de componente es requerido en este proyecto
            for (const ComponenteRequerido& componenteRequerido : proyecto.ComponentesRequeridos) {
                if (componenteRequerido.tipoComponente.codigo == tipoComponente.codigo &&
                    cantidad <= componenteRequerido.cantMinRequerida) {
                    // Busca el tipo de componente en la lista de tipos
                    for (Tipos& tipo : tipoComponente.tipos) {
                        if (tipo.codigo == tipoComponente.codigo && tipo.cantidad >= cantidad) {
                            // El componente es necesario y hay suficiente cantidad para prestar
                            PrestamoTiposC prestamo;
                            prestamo.tipoComponente = tipoComponente;
                            prestamo.proyecto = proyecto;
                            prestamo.cantidad = cantidad;
                            listaPrestamos.push_back(prestamo);
                            // Actualiza la cantidad disponible del tipo de componente
                            tipo.cantidad -= cantidad;
                            return true;
                        }
                    }
                }
            }
        }
    }
    // Si no se encuentra un proyecto que requiera este componente o no hay suficiente cantidad, muestra un mensaje de error
    cout << "No se puede prestar este componente debido a que no es necesario en ninguno de tus proyectos o no hay suficiente cantidad disponible." << endl;
    return false;
}
