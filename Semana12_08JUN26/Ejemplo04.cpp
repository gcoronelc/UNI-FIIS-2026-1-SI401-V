/*
Punteros y arreglos
En C++, el nombre de un arreglo se comporta en muchos casos como una dirección al primer elemento.
*/

#include <iostream>

using namespace std;

int main() {
	
    int numeros[4] = {10, 20, 30, 40};
    int n = 88;

    int* p = numeros;

    cout << *p << '\n';       // 10
    cout << *(p + 1) << '\n'; // 20
    cout << *(p + 2) << '\n'; // 30
    cout << *(p + 3) << '\n'; // 40
    cout << *(p + 4) << '\n'; // ? No se sabe que hay en ese espacio de memoria
    cout << *(p + 5) << '\n'; // ? No se sabe que hay en ese espacio de memoria

    return 0;
}
