#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream archivo;

    archivo.open("datos.txt", ios::app);

	archivo << endl << endl;
    archivo << "Alumno 1: Juan Perez - 20" << endl;
    archivo << "Alumno 2: Ana Contreras - 18" << endl;

    archivo.close();

    cout << "Datos agregados correctamente.";

    return 0;
}