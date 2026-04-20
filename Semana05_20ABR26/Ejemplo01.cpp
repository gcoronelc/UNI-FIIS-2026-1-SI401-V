#include <iostream>

using namespace std;

int main(){
	
	// Configuración 
	setlocale(LC_ALL, "Spanish");
	
	// Arreglo de notas
	int notas[] = {15,18,16,12,10,16};
	
	// Tamaño del arreglo
	int tamElemento = sizeof(notas[0]);
	int tamanio = sizeof(notas) / tamElemento;
	cout << "Tamanio de elemento: " << tamElemento << " Bytes" << endl;
	cout << "Tamanio del arreglo: " << tamanio << endl;
	
	// Recorrido del arreglo
	// La suma de notas
	int suma = 0;
	for(int i=0; i<tamanio;i++){
		suma += notas[i];
	}
	float promedio = suma*1.0/tamanio;
	cout << "Suma: " << suma << endl;
	cout << "Promedio: " << promedio << endl;
	
	
	
	
}