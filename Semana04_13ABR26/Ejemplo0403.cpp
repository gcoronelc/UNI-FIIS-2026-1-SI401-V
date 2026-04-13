/*
   Suma = 3/1 + 3/2 + 3/3 + 3/4 .... + 3/N
*/

#include <iostream>

using namespace std;

// Declarar la función

float terminoN(int n);
float sumatoria(int n);

int main(){
	
	// Variables
	int n;
	float termino, suma;
	
	// Lectura
	cout << "N (>0): ";
	cin  >> n;
	
	if(n<=0){
		cout << "N debe ser un valor positivo.";
		return 1;
	}
	
	// Proceso
	termino = terminoN(n);
	suma = sumatoria(n);
	
	// Reporte
	cout << endl;
	cout << "Termino: " << termino << endl;
	cout << "Sumatoria: " << suma << endl;
	
	
}


// Implementación

float terminoN(int n){
	float termino = 3 * 1.0 / n;
	return termino;
}

float sumatoria(int n){
	// Variables
	float suma = 0;
	// Proceso
	for(int i = 1; i <= n; i++){
		suma += (3*1.0/i);
	}
	return suma;
}



