#ifndef LISTAESPERA_H
#define LISTAESPERA_H

#include <string>
#include <list>
#include "Estudiante.h" 
#include "Componente.h" 

using namespace std;
/*
Fecha de inicio: 13/9/2023
Fecha última modificación: 13/9/2023 .
Esta clase representa la lista de espera
de estudiantes que solicitaron un componente
dentro del sistema. 
*/

//Se definen los atributos que utiliza la clase ListaEspera
class ListaEspera {
public:
    list<Estudiante> estudiantes;
    list<Componente> tiposComponentes;
    list<int> cantidad;

public:
    ListaEspera() = default; //se utiliza el constructor por defecto

    // Método que permite obtener una representación en string de la lista de espera
    string ToString();
};

#endif  // LISTAESPERA_H
