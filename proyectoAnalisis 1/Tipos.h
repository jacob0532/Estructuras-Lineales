#ifndef Tipos_H
#define Tipos_H

#include <string>

using namespace std;
/*
Fecha de inicio: 13/9/2023
Fecha última modificación: 18/9/2023.
la clase Tipos representa los tipos de
componentes existentes en el contexto del proyecto dentro del programa
*/

//Se definen los atributos que utiliza la clase Componente
class Tipos {
public:
    string codigo;
    string nombre;
    string descripcion;
    string dondeSeUtilizan;
    int cantidad;

public:
    Tipos() = default;
    Tipos(string codigo, string nombre, string descripcion, string dondeSeUtilizan, int cantidad); //constructor de la clase Tipos
    
    // Método que permite obtener una representación en string del tipo de componente
    string ToString();
};

#endif  // Tipos_H


