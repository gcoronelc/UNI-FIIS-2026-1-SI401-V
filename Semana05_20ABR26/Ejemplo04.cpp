/*
Generar una matriz de 5x4 y obtener la suma de cada fila.
El reporte debe tener el siguiente formato: 
Fila 1: 10 15 10 30 => 65 
Fila 2: 90 20 15 50 => 175 
Fila 3: 60 30 20 40 => 150 
Fila 4: 70 80 20 45 => 215 
Fila 5: 45 90 25 10 => 170

*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include<stdlib.h> 
#include <vector>

using namespace std;

// Declaraciones
const int FILAS = 5;
const int COLUMNAS = 4;
int matriz[FILAS][COLUMNAS];
int suma[FILAS];

// Funciones
void generarMatriz();
void calcularSuma();
void reporte();

int main(){
	generarMatriz();
	calcularSuma();
	reporte();
	return 0;
}

// Implementaciones

void reporte(){
	cout << "REPORTE\n";
	cout << string(30,'=') << endl;
	for (int f=0; f<FILAS; f++) { 
		cout << "Fila " << f << ": ";
		for(int c=0; c<COLUMNAS; c++){
			cout << setw(5) << matriz[f][c];
		} 
		cout << "  =>  " << suma[f] << endl;
	}
}

void calcularSuma(){
	int s;
	for (int f=0; f<FILAS; f++) { 
		s = 0; // Inicializas la suma en0 de la fila
		for(int c=0; c<COLUMNAS; c++){
			s += matriz[f][c];
		} 
		suma[f] = s;
	}
}

void generarMatriz(){
	int numero;
	srand(time(NULL)); 
	for (int f=0; f<FILAS; f++) { 
		for(int c=0; c<COLUMNAS; c++){
			numero = rand() % 89 + 10;
			matriz[f][c] = numero;
		} 
	}
}
