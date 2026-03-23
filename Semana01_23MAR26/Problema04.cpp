#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	// Variables 
	double radio, area;
	
	// Lectura y validacion
	// Principio: Fail Fast
	
	cout << "\nLECTURA DE DATOS";
	cout << "\n==========================";
	
	cout << "\nIngrese el radio:";
	cin  >> radio;
	
	if(radio<=0){
		cout << "\nn[ERROR] Valor del radio debe ser positivo.";
		return 1;
	}
	
	// Proceso
	
	area = M_PI * radio * radio;
	
	// Reporte
	
	cout << "\nREPORTE";
	cout << "\n==========================";
	cout << "\nRadio: " << radio << endl;
	cout << "\nArea: " << area << endl;
	
	return 0;
}