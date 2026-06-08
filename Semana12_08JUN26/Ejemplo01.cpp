#include <iostream>
#include <string>

using namespace std;

// Agrupa varios datos de diferentes tipos,
// pero que se encuentran relacionados
// formando una solo unidad.
// Esta definiendose un nuevo tipo.
struct Estudiante {
	string codigo;
	string nombre;
	int edad;
	double promedio;
};

void imprimir(Estudiante& est){
	est.promedio = 30;
	cout << endl << "===================================" << endl;
	cout << "Código: " << est.codigo << '\n';
	cout << "Nombre: " << est.nombre << '\n';
	cout << "Edad: " << est.edad << '\n';
	cout << "Promedio: " << est.promedio << '\n';
}

int main() {
	
    Estudiante estudiante1;
    Estudiante estudiante2;

    estudiante1.codigo = "2026001";
    estudiante1.nombre = "Ana Torres";
    estudiante1.edad = 18;
    estudiante1.promedio = 15.8;
    
    estudiante2.codigo = "2026002";
    estudiante2.nombre = "Gustavo Coronel";
    estudiante2.edad = 17;
    estudiante2.promedio = 28.50;

	imprimir( estudiante1);
	imprimir(estudiante2);
	
	cout << endl << estudiante1.promedio << "    " << estudiante2.promedio;

    return 0;
}
