#include <iostream>
#include <stdlib.h>
#include <ctime>
# include <algorithm>

using namespace std;

// Variables globales
int N;
int* arreglo;
double mediana, media;


// Funciones
void generaMatriz();
void mostrarMatriz();
void ordenarMatriz();
void calcularPromedio();
void calcularMediana();
void mostrarResultados();

int main(){
	generaMatriz();
	mostrarMatriz();
	ordenarMatriz();
	calcularPromedio();
	calcularMediana();
	mostrarResultados();
}


void generaMatriz(){
	// Generar valor de N
	srand(time(NULL));
	N = rand() % 11 + 5;
	// Generar el arreglo
	arreglo = new int[N];
	for(int i=0; i<N; i++){
		arreglo[i] = rand() % 20 + 10;
	}
}

void mostrarMatriz(){
	cout << "N = " << N << endl;
	cout << "Arreglo: ";
	for(int i=0; i<N; i++){
		cout << arreglo[i] << "   ";
	}
	cout << endl;
}

void ordenarMatriz(){
	sort(arreglo, arreglo + N);
}

void calcularPromedio(){
	int suma = 0;
	for(int i=0; i<N; i++){
		suma += arreglo[i];
	}
	media = suma * 1.0 / N;
}

void calcularMediana(){
	if(N%2 == 0){
		int a = arreglo[N/2];
		int b = arreglo[N/2 - 1];
		mediana = (a + b) / 2;
	} else {
		mediana = arreglo[N/2];
	}
}

void mostrarResultados(){
	cout << endl << endl;
	cout << "REPORTE" << endl;
	mostrarMatriz();
	cout << "Mediana: " << mediana << endl;
	cout << "Media: " << media << endl;
}
