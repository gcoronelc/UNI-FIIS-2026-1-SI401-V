#include <iostream>
#include <string>

using namespace std;


int main(){
	
	int edad = 40;
	int* puntero = &edad;
	
	
	cout << edad << "     " << puntero;
	
	cout << endl << "=======================================" << endl;
	cout << "Direccion de memoria: " << puntero << "   " << &edad << endl;
	cout << "Valor almacenado: " << *puntero << "   " << edad << endl;
	
	
	return 0;
	
	
}
