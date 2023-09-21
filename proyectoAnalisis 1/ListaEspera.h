#ifndef LISTAESPERA_H
#define LISTAESPERA_H

#include <string>
#include <list>
#include "Estudiante.h" // Incluimos el encabezado de Estudiante
#include "Componente.h" // Incluimos el encabezado de Componente

using namespace std;

class ListaEspera {
public:
    list<Estudiante> estudiantes;
    list<Componente> tiposComponentes;
    list<int> cantidad;

public:
    ListaEspera() = default;

    // Método para obtener una representación en string de la lista de espera
    string ToString();
};

#endif  // LISTAESPERA_H
