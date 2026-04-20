/*
Objetivo: Encontrar el primer y ultimo puesto.
*/

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Datos y Variables
int notas[] = {15,18,16,12,10,16};
string estudiantes[] = {"Pedro","Alejandra","Gustavo","Doris","Manuel","Claudia"};
int tamanio;
string primero, ultimo;

// Declaracion de Funciones y Procedimientos
void calcularTamanio();
void mostrarDatos();
void ordenar();
void detRequerimiento();
void reporte();


int main(){
	
	// Configuración 
	setlocale(LC_ALL, "Spanish");
	
	// Proceso
	calcularTamanio();
	mostrarDatos();
	ordenar();
	cout << endl;
	mostrarDatos();
	detRequerimiento();
	reporte();
	
}

// Implementacion de Funciones y Procedimientos

void calcularTamanio(){
	// Tamaño del arreglo
	int tamElemento = sizeof(notas[0]);
	tamanio = sizeof(notas) / tamElemento;
}

void mostrarDatos(){
	cout << "\nLISTADO DE ESTUDIANTE\n";
	cout << string(30, '=') << endl;
	cout << setw(4) << "NRO" << setw(15) << "ESTUDIANTE" << setw(8) << "NOTA" << endl;
	for(int i=0; i<tamanio;i++){
		cout << setw(4) << i
			 << setw(15) << estudiantes[i] 
			 << setw(8)  << notas[i] << endl;
	}	
}

void ordenar(){
	for(int i=0; i<(tamanio-1); i++){
		for(int j=i+1; j<tamanio; j++){
			if(notas[i] < notas[j]){
				int t1 = notas[i];
				notas[i] = notas[j];
				notas[j] = t1;
				string t2 = estudiantes[i];
				estudiantes[i] = estudiantes[j];
				estudiantes[j] = t2;
			}
		}
	}
}

void detRequerimiento(){
	ostringstream repo1, repo2;
	repo1 << "Primer lugar: " 
		  << estudiantes[0] 
		  << " (Nota:" << notas[0] << ")\n";
	repo2 << "Ultimo lugar: " 
		  << estudiantes[tamanio-1] 
		  << " (Nota:" << notas[tamanio-1] << ")\n";
	primero = repo1.str();
	ultimo = repo2.str();
}

void reporte(){
	cout << endl;
	cout << "Cantidad de estudiantes: " << tamanio << endl;
	cout << primero;
	cout << ultimo;
}