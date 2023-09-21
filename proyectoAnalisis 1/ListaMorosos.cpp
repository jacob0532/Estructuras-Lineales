#include "ListaMorosos.h"
#include <iostream>

using namespace std;

// Método para agregar un estudiante moroso a la lista
ListaMorosos::AgregarMoroso(const Estudiante& estudiante, const Componente& tipoComponente, int cantidad) {
    estudiantes.push_back(estudiante);
    tiposComponentes.push_back(tipoComponente);
    cantidadPendiente.push_back(cantidad);
}

// Método para obtener una representación en string de la lista de morosos
string ListaMorosos::ToString() {
    string listaString = "Lista de Morosos:\n";

    // Iteramos a través de las listas y generamos la representación en cadena
    auto estudianteIter = estudiantes.begin();
    auto tipoComponenteIter = tiposComponentes.begin();
    auto cantidadIter = cantidadPendiente.begin();

    while (estudianteIter != estudiantes.end() &&
           tipoComponenteIter != tiposComponentes.end() &&
           cantidadIter != cantidadPendiente.end()) {
        listaString += "Estudiante: " + estudianteIter->ToString() + "\n";
        listaString += "Tipo de Componente: " + tipoComponenteIter->ToString() + "\n";
        listaString += "Cantidad Pendiente: " + to_string(*cantidadIter) + "\n\n";

        ++estudianteIter;
        ++tipoComponenteIter;
        ++cantidadIter;
    }

    return listaString;
}
