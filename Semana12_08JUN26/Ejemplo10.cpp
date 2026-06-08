// Funciones que modifican arreglos

#include <iostream>

using namespace std;

void duplicarValores(int* numeros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        numeros[i] = numeros[i] * 2;
    }
}

void mostrarValores(const int* numeros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << numeros[i] << " ";
    }
    cout << '\n';
}

int main() {
    int datos[4] = {5, 10, 15, 20};

    cout << "Valores originales: ";
    mostrarValores(datos, 4);

    duplicarValores(datos, 4);

    cout << "Valores duplicados: ";
    mostrarValores(datos, 4);

    return 0;
}

