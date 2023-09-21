#ifndef LISTAMOROSOS_H
#define LISTAMOROSOS_H

#include <string>
#include <list>

#include "Estudiante.h"
#include "Componente.h" 

using namespace std;

class ListaMorosos {
public:
    list<Estudiante> estudiantes;
    list<Componente> tiposComponentes;
    list<int> cantidadPendiente;

public:
    ListaMorosos() = default;
    AgregarMoroso(const Estudiante& estudiante, const Componente& tipoComponente, int cantidad);

    // Método para obtener una representación en string de la lista de morosos
    string ToString();
};

#endif  // LISTAMOROSOS_H