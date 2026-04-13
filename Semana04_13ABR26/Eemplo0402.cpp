#include <iostream>

using namespace std;

// Declarar la función
bool esPrimo( int n );

int main(){
	
	// Datos
	int num = 11;
	
	// Proceso
	bool primo = esPrimo(num);
	string mensaje = (primo)?"Es primo":"No es primo";
	
	// Reporte
	cout << "Numero: " << num << endl;
	cout << "Mensaje: " << mensaje << endl;
	
}	


// Implementar la función

bool esPrimo( int n ){
	// Consistencia
	if(n==1){
		return false;
	}
	// Variables
	bool primo = true; // Se asume que es primo
	// Proceso
	cout << "i = ";
	for(int i=2; i*i <= n; i++){
		cout << i << " ";
		if(n%i == 0){
			primo = false;
			break;
		}
	}
	cout << endl;
	// Reporte
	return primo;
}

	
