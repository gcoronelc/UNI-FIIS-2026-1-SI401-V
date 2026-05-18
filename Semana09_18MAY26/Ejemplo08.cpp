#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ofstream archivo;

    archivo.open("datos.txt");

    archivo << "Universidad Nacional de Ingenieria" << endl;
    archivo << "Curso de Programacion" << endl;
    archivo << "Profesor: Gustavo Coronel" << endl;

    archivo.close();

    cout << "Archivo generado correctamente";

    return 0;
}
