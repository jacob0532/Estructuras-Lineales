#include "ListaEspera.h"
#include <iostream>

// Método para obtener una representación en string de la lista de espera
string ListaEspera::ToString() {
    string listaString = "Lista de Espera:\n";

    // Iteramos a través de las listas y generamos la representación en cadena
    auto estudianteIter = estudiantes.begin();
    auto tipoComponenteIter = tiposComponentes.begin();
    auto cantidadIter = cantidad.begin();

    while (estudianteIter != estudiantes.end() &&
           tipoComponenteIter != tiposComponentes.end() &&
           cantidadIter != cantidad.end()) {
        listaString += "Estudiante: " + estudianteIter->ToString() + "\n";
        listaString += "Tipo de Componente: " + tipoComponenteIter->ToString() + "\n";
        listaString += "Cantidad: " + to_string(*cantidadIter) + "\n\n";

        ++estudianteIter;
        ++tipoComponenteIter;
        ++cantidadIter;
    }

    return listaString;
}
