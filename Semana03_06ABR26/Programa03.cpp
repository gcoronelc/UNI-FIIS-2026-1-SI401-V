#include <iostream> 
#include <sstream> 
using namespace std; 

int leerEnteroPositivo( string etiqueta );

int main() { 

	// Variables 
	int m, n, resto; 
	stringstream resultado; // Para el resultado 
	
	// Lectura de datos 
	cout << "LECTURA\n"; 
	cout << "==============================\n"; 
	m = leerEnteroPositivo( "Valor de m: " ); 
	n = leerEnteroPositivo( "Valor de n: " ); 
	
	// Normaizar los datos
	if(m > n ){
		int t = m;
		m = n;
		n = t;
	}
	
	
	// Proceso
	resultado << "Resultado: "; 
	for (int i = m; i <= n; i++) { 
		resto = i % 2; 
		if (resto == 1) { 
			resultado << " " << i; 
		} 
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