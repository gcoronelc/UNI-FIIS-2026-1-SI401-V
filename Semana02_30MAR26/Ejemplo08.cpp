#include <iostream>
#include <cctype>
using namespace std;

int main(){
	
	// Variables
	float x, y;	
	
	// Lectura
	cout << "Ingrese x: ";
	cin  >> x;
	
	// Proceso
	if(x<=11) y = 3*x + 36;
	else if(x<=33) y = x*x - 10;
	else if(x<=64) y = x + 6;
	else y = 0;
	
	// Reporte
	cout << "\nValor de y: " << y;
	
	return 0;
	
}