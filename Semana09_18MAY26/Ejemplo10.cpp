#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream archivo("datos.txt");

    if(!archivo){
        cout << "No se pudo abrir el archivo";
        return 1;
    }

    cout << "Archivo abierto correctamente";

    archivo.close();

    return 0;
}
