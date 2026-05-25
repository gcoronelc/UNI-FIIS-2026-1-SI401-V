#include <iostream>
#include <vector>   // obligatorio para usar vector
#include <cstdlib>   // rand() y srand()
#include <ctime>     // time()

#include "Punto.h"
using namespace std;

vector<Punto> puntos;
int N;
Punto pLejano;
float distPromedio;

void leerValorN(){
	cout << "Valor para N: ";
	cin  >> N;
}

void generarPuntos(){
	// Inicializar la semilla UNA SOLA VEZ
    srand(time(0));
	for(int i=1; i<=N; i++){
		int x = rand() % 50;
		int y = rand() % 50;
		Punto p(x,y);
		puntos.push_back(p);
	}
}

void puntoLejano(){
	pLejano = puntos[0];
	for(int i=1; i<N; i++){
		if(pLejano.distancia() < puntos[i].distancia()){
			pLejano = puntos[i];
		}
	}
}

void distanciaPromedio(){
	distPromedio = 0;
	for(int i=0; i<N; i++){
		distPromedio += puntos[i].distancia();
	}
	distPromedio = distPromedio / N;
}


void mostrarArreglo(){
	cout << endl;
	cout << "Arreglo: ";
	for(int i = 0; i < N; i++){
		Punto p = puntos[i];
		cout << p.getPunto() << " ";
	}
	cout << endl;
}
int main(){
	// Datos
	leerValorN();
	
	// Proceso
	generarPuntos();
	puntoLejano();
	distanciaPromedio();
	
	// Reporte
	mostrarArreglo();
	cout << "Mas lejano: " << pLejano.getPunto() << endl;
	cout << "Distancia promedio: " << distPromedio << endl;
	return 0;
}