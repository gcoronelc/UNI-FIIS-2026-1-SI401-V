// Ejemplo didactico

#include <iostream>

using namespace std;

int main() {
	
	// Varable tipo int
	int valor = 25;
	
	// Declaramos un puntero que apunta a la variable valor.
	int* puntero = &valor;
	
	cout << "Valor original: " << valor << '\n';
	
	// Modificamos el valor usando el puntero.
	*puntero = 80;
	
	cout << "Valor modificado: " << valor << '\n';
	
	return 0;
}
