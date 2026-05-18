#include <iostream>
using namespace std;

void mostrarMensaje(string nombre = "Invitado"){
    cout << "Bienvenido " << nombre << endl;
}

int main(){

    mostrarMensaje();
    mostrarMensaje("Gustavo Coronel");

    return 0;
}
