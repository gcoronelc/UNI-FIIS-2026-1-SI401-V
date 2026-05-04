#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// Variables

struct Cuota {
	int cuota;
	float capital;
	float cuotaCapital;
	float cuotaInteres;
    float cuotaTotal;
};

float capital, cuotaCapital, cuotaInteres, cuotaTotal;
float interes, capitalOriginal;
int meses, riesgo;
Cuota* arreglo;

// Funciones
void lectura();
void proceso();
void reporte();

// Función principal
int  main(){
	lectura();
	proceso();
	reporte();
	return 0;
}


void reporte(){
	cout << endl;
	cout << "REPORTE\n";
	cout << "=====================\n";
	cout << "Capital: S/. " << capitalOriginal << endl;
	cout << "Interes mensual: " << interes * 100 << "%" << endl;
	cout << setw(6) << "CUOTA" << setw(8) << "CAPITAL";
	cout << setw(10) << "C.CAPITAL" << setw(10) << "C.INTERES";
	cout << setw(10) << "C.TOTAL";
	cout << endl;
	for(int i=0; i<meses; i++){
		cout << setw(6) << arreglo[i].cuota << setw(8) << arreglo[i].capital;
		cout << setw(10) << arreglo[i].cuotaCapital << setw(10) << arreglo[i].cuotaInteres;
		cout << setw(10) << arreglo[i].cuotaTotal;
		cout << endl;
	}
}

void proceso(){
	capitalOriginal = capital;
	arreglo = new Cuota[meses];
	cuotaCapital = capital / meses;
	switch(riesgo){
		case 1: interes = 0.015; break;
		case 2: interes = 0.028; break;
		case 3: interes = 0.040; break;
		case 4: interes = 0.060; break;
	}
	for(int i=0; i<meses; i++){
		cuotaInteres = capital * interes;
		cuotaTotal = cuotaCapital + cuotaInteres;
		arreglo[i].cuota = i+1;
		arreglo[i].capital = capital;
		arreglo[i].cuotaCapital = cuotaCapital;
		arreglo[i].cuotaInteres = cuotaInteres;
		arreglo[i].cuotaTotal = cuotaTotal;
		// Para la siguiente iteracion
		capital = capital - cuotaCapital;
	}
}


void lectura(){
	cout << "LECTURA DE DATOS\n";
	cout << "=====================\n";
	cout << "Importe del prestamo? "; cin >> capital;
	cout << "Meses? "; cin >> meses;
	cout << "Riesgo? "; cin >> riesgo;
	cout << endl << endl;
}


 
