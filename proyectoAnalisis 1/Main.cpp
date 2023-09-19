#include <iostream>
#include "Curso.h"
#include "Estudiante.h"
#include "Componente.h"

int main() {
    // Ejemplo para la clase Curso
    Curso curso1("C001", "Programación", 3);
    cout << "Representación de Curso:\n" << curso1.ToString() << "\n\n";

    // Ejemplo para la clase Estudiante
    Estudiante estudiante1("2021001", "Juan", "Pérez", "123456789", 20, "Ciudad X");
    cout << "Representación de Estudiante:\n" << estudiante1.ToString() << "\n\n";

    // Ejemplo para la clase Componente
    Componente componente1("C001", "CPU", "Procesador central", "Activo", "Sistemas embebidos");
    cout << "Representación de Componente:\n" << componente1.ToString() << "\n";

    return 0;
}
