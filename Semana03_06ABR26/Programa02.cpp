#include <iostream> 
#include <sstream> 
using namespace std; 
int main() { 

	// Variables 
	int n, i; 
	stringstream resultado; // Para el resultado 
	
	// Lectura de datos 
	cout << "LECTURA\n"; 
	cout << "==============================\n"; 
	do{
		cout << "Valor de n: "; 
		cin  >> n;
		if(n<=0){
			cout << "[ERROR] El valor de n debe ser positivo.\n";
		}
	}while (n<=0);
 
	
	// Proceso 
	resultado << "Serie: "; 
	i = 1; 
	while (i <= n) { 
		resultado << " " << i; i++; 
	} 
	
	// Reporte 
	cout << "\n"; 
	cout << "REPORTE\n";
	cout << "==============================\n"; 
	cout << resultado.str(); 
	cout << "\n"; 
	
	// Fin 
	return 0; 
	
}
	
	
	