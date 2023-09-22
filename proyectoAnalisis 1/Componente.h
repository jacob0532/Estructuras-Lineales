#ifndef COMPONENTE_H
#define COMPONENTE_H

#include "Tipos.h"

#include <string>
#include <list>

using namespace std;


/*
Fecha de inicio: 13/9/2023
Fecha última modificación: 13/9/2023 .
Esta clse se encarga de representar los componentes
dentro del contexto del programa
*/

// Definición del enumerado para la clasificación
enum Clasificacion {
    ACTIVO,
    PASIVO
};

//Se definen los atributos que utiliza la clase Componente
class Componente {
public:
    string codigo;
    string nombre;
    string descripcion;
    Clasificacion clasificacion; 
    string aplicaciones;
    list<Tipos> tipos; 

public:
    Componente() = default;
    Componente(string codigo, string nombre, string descripcion, Clasificacion clasificacion, string aplicaciones); //se define el constructor
    
    // Este método permite obtener una representación en string del componente
    string ToString() const;
};

#endif  // COMPONENTE_H


