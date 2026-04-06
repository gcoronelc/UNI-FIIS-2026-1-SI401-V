#include <iostream> 
using namespace std; 

int leerEnteroPositivo( string etiqueta );

int main() { 

	// Variables 
	int n; 
	long factorial; 
	
	// Lectura de datos 
	cout << "LECTURA\n"; 
	cout << "==============================\n"; 
	n = leerEnteroPositivo( "Valor de n: " ); 
	
	// Proceso 
	factorial = 1; 
	while (n >= 1) { 
		factorial *= n--; 
	} 
	
	// Reporte 
	cout << "\n"; 
	cout << "REPORTE\n"; 
	cout << "==============================\n"; 
	cout << "Factorial: " << factorial; 
	cout << "\n";
	
	// Fin 
	return 0; 
	
}

int leerEnteroPositivo( string etiqueta ){
	int num;
	do{
		cout << etiqueta;
		cin  >> num;
		if(num <= 0){
			cout << "Ingrese un valor entero mayor que cero.\n";
		}
	} while(num <= 0);
	return num;	
}