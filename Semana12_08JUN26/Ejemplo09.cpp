#include <iostream>

using namespace std;

void mostrarArreglo(int* numeros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        // cout << numeros[i] << " ";
        cout << *(numeros +i) << " ";
    }
    std::cout << '\n';
}

int main() {
	
    int datos[5] = {10, 20, 30, 40, 50};

    mostrarArreglo(datos, 5);

    return 0;
    
}
