#include <iostream>

using namespace std;

// Declarar la función
float llerNota(string etiqueta);


int main(){
	
	// Variables
	float nota1, nota2, nota3, nota4, nota5;
	
	// Lectura
	nota1 = llerNota("\nIngreso Nota 1: ");
	nota2 = llerNota("\nIngreso Nota 2: ");
	nota3 = llerNota("\nIngreso Nota 3: ");
	nota4 = llerNota("\nIngreso Nota 4: ");
	nota5 = llerNota("\nIngreso Nota 5: ");
	
	
	// Proceso

	
	// Reporte
	cout << endl;
	//cout << "Termino: " << termino << endl;
	//cout << "Sumatoria: " << suma << endl;
	
	
}


float llerNota(string etiqueta){
	float nota;
	do{
		cout << etiqueta;
		cin  >> nota;
		if(nota<0.0 || nota>20.0){
			cout << "\nError: la nota debe estar en el rango [0.0,20.0].\n";
		}
	} while (nota<0.0 || nota>20.0);
	return nota;
}



