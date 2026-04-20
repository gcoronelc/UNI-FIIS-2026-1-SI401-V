// La clase vector

#include <iostream>
#include <iomanip>
#include <sstream>
#include<stdlib.h> 
#include <vector>

using namespace std;

// Variables
int tamanio;
vector<int> listaGenerada;
ostringstream primos, arreglo;

// Declaracion de funciones
void lecturaDatos();
void generarNumeros();
bool esPrimo(int n);
void proceso();
void reporte();

int main(){
	lecturaDatos();
	generarNumeros();	
	proceso();
	reporte();
	return 0;
}

// Implementacion de funciones

void reporte(){
	cout << endl << endl;
	cout << "REPORTE\n";
	cout << string(20,'=') << endl;
	cout << arreglo.str();
	cout << primos.str();
}

void proceso(){
	string coma1 = "";
	string coma2 = "";
	arreglo << "Arreglo generado: ["; 
	primos << "Numeros primos: ["; 
	for (int numero: listaGenerada) {
		arreglo << coma1 << numero;
		coma1 = ", ";
		if(esPrimo(numero)){
			primos << coma2 << numero;
			coma2 = ", ";
		}
	}
	arreglo << "]\n";
	primos  << "]\n"; 
}

bool esPrimo(int n){
	if(n==1){
		return false;
	}
	bool siPrimo = true;
	for(int i=2;i<n;i++){
		if(n%i==0){
			siPrimo = false;
			break;
		}
	}
	return siPrimo;
}

void generarNumeros(){
	int numero;
	srand(time(NULL)); 
	for (int i = 0; i < tamanio; i++) { 
		numero = rand() % 30 + 1; 
		listaGenerada.push_back(numero); 
	}
}

void lecturaDatos(){
	cout << "LECTURA DE DATOS\n";
	cout << string(30,'=') << endl;
	do{
		cout << "Tamanio del arreglo: ";
		cin  >> tamanio;
		if(tamanio<5 || tamanio>20){
			cout << "[ERROR] El tamanio debe estar en el rango de [5,20]\n\n";
		}
	}while (tamanio<5 || tamanio>20);	
}