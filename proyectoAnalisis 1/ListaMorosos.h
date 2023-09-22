#ifndef LISTAMOROSOS_H
#define LISTAMOROSOS_H

#include <string>
#include <list>

#include "Estudiante.h"
#include "Componente.h" 

using namespace std;
/*
Fecha de inicio: 15/9/2023
Fecha última modificación: 19/9/2023 .
Esta clase representa dentro del sistema
la lista de morosidad de estudiantes con los
componentes a devolver
*/

//Se definen los atributos que utiliza la clase Componente
class ListaMorosos {
public:
    list<Estudiante> estudiantes;
    list<Componente> tiposComponentes;
    list<int> cantidadPendiente;

public:
    ListaMorosos() = default;
    int AgregarMoroso(const Estudiante& estudiante, const Componente& tipoComponente, int cantidad); //constructor de lista morosos

    // Método que permite obtener una representación en string de la lista de morosos
    string ToString();
};

#endif  // LISTAMOROSOS_H