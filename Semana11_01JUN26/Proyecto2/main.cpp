#include <iostream>
#include <vector>

#include "ManejadorArreglos.h"

using namespace std;

int main() {
	
	ManejadorArreglos ma(40);
	ma.mostrarArreglos();
	
	cout << "\n============================\n";
	
	vector<int> comun = ma.obtenerComunes();
	cout << "Comun: ";
	for(int x: comun)
		cout << x << "  ";
	cout << endl;
	
	cout << "\n============================\n";
	
	vector<int> dife = ma.obtenerDiferencia();
	cout << "Diferencia: ";
	for(int x: dife)
		cout << x << "  ";
	cout << endl;
	
	cout << "\n============================\n";
	
	vector<int> suma = ma.obtenerSuma();
	cout << "Suma: ";
	for(int x: suma)
		cout << x << "  ";
	cout << endl;
	
	return 0;
}