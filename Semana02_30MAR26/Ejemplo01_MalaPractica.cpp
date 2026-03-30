#include <iostream>
#include <cctype>
using namespace std;

int main(){

	// Variables
	char categoria;
	float sueldo, porcAumento, aumento, nuevoSueldo;	
	
	
	// Lectura 
	cout<<"Lectura de datos\n\n";
	//categoria
	cout<<"Ingrese la categoria (S,C,D,E): ";
	cin>> categoria;
	categoria=toupper(categoria);
	if (categoria!='S' && categoria !='C'&& categoria != 'D' && categoria != 'E' ){
		cout<<"Error, categoria incorrecta";
		return 1;
	}
	// sueldo
	cout << "Ingrese el sueldo:  " ;
	cin >> sueldo;
	if (sueldo< 0){
		cout << "Error, sueldo incorrecto";
		return 1;
	}
	
	// Proceso
	//Porcentaje de un medio
	switch(categoria){
		case 'S':
			porcAumento=0.20;
			aumento=sueldo*porcAumento;
			nuevoSueldo=sueldo+aumento;			
			break;
		case 'C':
			porcAumento=0.10;
			aumento=sueldo*porcAumento;
			nuevoSueldo=sueldo+aumento;			
			break;
		case 'D':
			porcAumento=0.05;
			aumento=sueldo*porcAumento;
			nuevoSueldo=sueldo+aumento;			
			break;
		case 'E':
			porcAumento=0;
			aumento=sueldo*porcAumento;
			nuevoSueldo=sueldo+aumento;			
			break;
	}
	
	// Reporte
		
	cout << "Su sueldo actual es : " << sueldo << endl;
	cout << "Su aumento es: " << aumento << endl;
	cout << " Su nuevo sueldo es : " << nuevoSueldo;
	
	return 0;
}