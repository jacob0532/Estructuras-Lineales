#ifndef LISTAMOROSOS_H
#define LISTAMOROSOS_H

#include <string>
#include <list>

#include "Estudiante.h"
#include "Componente.h" 

using namespace std;
/*
Fecha de inicio: 15/9/2023
Fecha última modificación: 15/9/2023 .
Descripción para cada estructura (clase) y su uso en el programa,
Describir cada función e instrucciones dentro de estas.*/
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