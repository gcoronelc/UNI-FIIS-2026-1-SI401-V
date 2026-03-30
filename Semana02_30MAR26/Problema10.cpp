#include <iostream>
using namespace std;

int main(){
	
	// Variables
	int nota;
	string categoria, condicion;
	
	// Lectura con principio Fail First
	cout << "\n\n";
	cout << "LECTURA\n";
	cout << "================\n";
	cout << "Nota [0,20]:";
	cin  >> nota;
	
	if(nota<0 || nota>20){
		cout << "\n\n";
		cout << "[ERROR] La nota de ser vigecimal.\n";
		return 1;
	}
	
	
	// Proceso aplicando buenas practicas
	
	// La categoria
	if(nota>=18){
		categoria = "Excelente";
	} else if(nota>=15){
		categoria = "Bueno";
	} else if(nota>=11){
		categoria = "Regular";
	} else if(nota>=6){
		categoria = "Deficiente";
	} else{
		categoria = "Reprobado";
	}
	
	// La condicion - Caso 1
	//condicion = (nota>=11)?"Aprobado":"Desaprobado";
	
	// La condicion - Caso 2
	/*if(nota>=11){
		condicion = "Aprobado";
	} else {
		condicion = "Desaprobado";
	}*/
	
	// La condicion - Caso 3
	condicion = "Desaprobado";
	if(nota>=11){
		condicion = "Aprobado";
	} 
	
	// Reporte
	cout << "\n\n";
	cout << "REPORTE\n";
	cout << "Nota: " << nota << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Condicion: " << condicion << endl;
	
}


