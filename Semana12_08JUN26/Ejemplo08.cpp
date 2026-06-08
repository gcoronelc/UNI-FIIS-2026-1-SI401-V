// Parametro tipo puntero

#include <iostream>

void modificarValor(int* puntero) {
    *puntero = 100;
}

int main() {
	
    int numero = 20;

    std::cout << "Antes: " << numero << '\n'; // 20

    modificarValor(&numero);

    std::cout << "Después: " << numero << '\n'; // 100

    return 0;
}
