#ifndef Tipos_H
#define Tipos_H

#include <string>

using namespace std;
/*
Fecha de inicio: 15/9/2023
Fecha última modificación: 15/9/2023 .
Descripción para cada estructura (clase) y su uso en el programa,
Describir cada función e instrucciones dentro de estas.*/
class Tipos {
public:
    string codigo;
    string nombre;
    string descripcion;
    string dondeSeUtilizan;
    int cantidad;

public:
    Tipos() = default;
    Tipos(string codigo, string nombre, string descripcion, string dondeSeUtilizan, int cantidad);
    
    // Método para obtener una representación en string del tipo de componente
    string ToString();
};

#endif  // Tipos_H


