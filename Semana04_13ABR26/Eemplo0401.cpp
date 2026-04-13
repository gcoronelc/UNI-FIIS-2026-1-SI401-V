#include <iostream>

using namespace std;

// Declarar la función
int sumar(int a, int b);

int main(){
	
	// Datos
	int m = 8;
	int n = 7;
	
	// Proceso
	int s = sumar(m,n);
	
	// Reporte
	cout << "Suma: " << s << endl;
	
}	


// Implementar la función

int sumar(int a, int b){
	int s = a + b;
	return s;
}

	
