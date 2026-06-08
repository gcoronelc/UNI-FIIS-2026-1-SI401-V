/*
Punteros y estructuras
Los punteros también pueden apuntar a estructuras.
*/

#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    double promedio;
};

int main() {
    Estudiante estudiante = {"Gustavo Coronel", 18, 19.5};

    Estudiante* pEstudiante = &estudiante;

	pEstudiante->nombre = "Juan Perez";

    cout << "Nombre: " << pEstudiante->nombre << '\n';
    cout << "Edad: " << pEstudiante->edad << '\n';
    cout << "Promedio: " << pEstudiante->promedio << '\n';

    return 0;
}
