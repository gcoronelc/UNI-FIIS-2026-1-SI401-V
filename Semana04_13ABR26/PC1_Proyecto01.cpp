/*
Datos de entrada
-------------------------
- sueldo base
- anios

Datos de salida
------------------------
- sueldo base
- anios
- porcentajeBono
- importeBono
- sueldoFinal

*/

#include <iostream>

using namespace std;

int main(){
	
	// Variables
	float sueldoBase, porcentajeBono, importeBono, sueldoFinal;
	int anios;
	
	// Lectura
	cout << "LECTURA DE DATOS\n";
	
	cout << "Sueldo base: ";
	cin  >> sueldoBase;
	if(sueldoBase<= 0.0){
		cout << "El sueldo debe ser un valor positivo.";
		return 1;
	}
	
	cout << "Años de antiguedad: ";
	cin  >> anios;
	if(anios <= 0.0){
		cout << "Los anios de servicio debe ser un valor positivo.";
		return 1;
	}
		
	// Proceso
	if(0 && anios <= 3){
		porcentajeBono = 0.0;
	} else if( anios <= 8 ){
		porcentajeBono = 0.05;
	} else if(anios <= 13 ){
		porcentajeBono = 0.10;
	} else{
		porcentajeBono = 0.15;
	}
	importeBono = sueldoBase * porcentajeBono;
	sueldoFinal = sueldoBase + importeBono;
	
	// Reporte
	cout << "Reporte \n";
	cout << "Sueldo base: " << sueldoBase << endl;
	cout << "Anios de antiguedad: " << anios << endl;
	cout << "Porcentaje de Bono: " << porcentajeBono << endl;
	cout << "Importe de Bono: " << importeBono << endl;
	cout << "Sueldo final: " << sueldoFinal << endl;
	
	return 0;
	
}
