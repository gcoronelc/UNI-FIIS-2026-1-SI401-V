/* 

ANALISIS

Datos de entrada
- Plan
- Consumo en minutos
- Es estudiante

Datos de dalida
- Importe base
- munutos en exceso
- Costo del minuto
- Importe por exceso
- Importe total

Datos auxiliares
- minutos del plan
- Costo por exceso por minuto

*/

#include <iostream>

using namespace std;

int main(){
	
	// Variables
	int plan, consumoMinutos; 
	int estudiante; // 1: si  2: No
	float costoExceso, minutosExceso, importeExceso;
	float importeBase, importeTotal;
	int minutosPlan;
	
	
	// Lectura de datos
	cout << "Plan (1,2,3): ";
	cin  >> plan;
	if( plan<1 || plan>3 ){
		cout << "El plan es incorrecto.\n";
		return 1;
	}
	
	cout << "Minutos consumidos: ";
	cin  >> consumoMinutos;
	if( consumoMinutos < 0 ){
		cout << "Los minutos consumidos debe ser positivo.\n";
		return 1;
	}
	
	cout << "Es estudiante (1:Si, 2:No): ";
	cin  >> estudiante;
	if( estudiante != 1 && estudiante != 2 ){
		cout << "Ingrese un valor correcto.\n";
		return 1;
	}
	
	// Proceso
	switch(plan){
		case 1:
			importeBase = 29.0;
			minutosPlan = 100;
			costoExceso = 0.40;
			break;
		case 2:
			importeBase = 45.0;
			minutosPlan = 250;
			costoExceso = 0.30;
			break;	
		case 3:
			importeBase = 65.0;
			minutosPlan = 500;
			costoExceso = 0.20;
			break;				
	}
	minutosExceso = (consumoMinutos>minutosPlan)?consumoMinutos-minutosPlan:0;
	importeExceso = minutosExceso * costoExceso;
	importeTotal = importeBase + importeExceso;
	
	// Reporte
	cout << "REPORTE\n";
	cout << "Importe base: " << importeBase << endl;
	cout << "Importe exceso: " << importeExceso << endl;
	cout << "Importe total: " << importeTotal << endl;
	
}

