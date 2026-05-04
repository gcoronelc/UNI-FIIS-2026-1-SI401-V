#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Variables
struct Alumno {
	string nombre;
	int nota;
};
const int N = 5;
Alumno arreglo[N];

// Funciones
void lectura();
void ordenarPorMerito();
void reporte();

// Funcion principal
int main(){
	
	lectura();
	ordenarPorMerito();
	reporte();
	return 0;
}

void reporte(){
	cout << endl << endl;
	cout << setw(20) << "ALUMNO" << setw(10) << "NOTA" << endl;
	for(Alumno a: arreglo){
		cout << setw(20) << a.nombre << setw(10) << a.nota << endl;
	}
}

void ordenarPorMerito(){
	for(int i=0; i<(N-1); i++){
		for(int j=i+1; j<N; j++){
			if(arreglo[i].nota < arreglo[j].nota){
				Alumno t = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = t;
			}
		}
	}
}

void lectura(){
	cout << "LECTURA DE DATOS\n";
	for(int i=0; i<N; i++){
		cout << "\nAlumno (" << (i+1) << "):\n";
		cout << "Nombre: "; cin >> arreglo[i].nombre; 	
		cout << "Nota: "; cin >> arreglo[i].nota;
	}
}