#include <iostream>
#include <cctype>
using namespace std;

int main(){
	
	// Variables
	char genero;
	float precio, porcDsct1, porcDsct2, total;
	float descuento1, descuento2, totalVenta;
	int cantidad;
	
	// Lectura de datos
	cout << "LECTURA DE DATOS\n";
	cout << "====================\n";
	// Genero
	cout << "Genero (M/F): ";
	cin  >> genero;
	genero = toupper(genero);
	if(genero!='M' && genero!='F'){
		cout << "ERROR, genero incorrecto.";
		return 1;
	}
	// Precio
	cout << "Precio: ";
	cin  >> precio;
	if(precio<0){
		cout << "ERROR, precio incorrecto.";
		return 1;
	}
	
	cout<< "Cantidad: ";
	cin>>cantidad;
	if(cantidad<=0){
		cout << "ERROR, cantidad incorrecta.";
		return 1;
	}
	
	// Proceso
	switch(genero){
		case 'M':
			porcDsct1 = 0.18;
			porcDsct2 = (cantidad>10)?0.50:0.20;
			break;
		case 'F':
			porcDsct1 = 0.25;
			porcDsct2 = (cantidad>10)?0.40:0.30;
			break;		
	}
	
	total = cantidad * precio;
	descuento1 = porcDsct1 * total;
	descuento2 = porcDsct2 * total;
	totalVenta = total - descuento1 - descuento2;
	
	// Reporte
	cout<< "Total: " << total << endl;
	cout<< "Descuento 1: " << descuento1 << endl;
	cout<< "Descuento 2: " << descuento2 << endl;
	cout<< "Total a pagar: " << totalVenta << endl;
	
	return 0;
}