#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream archivo;
    string linea;

    archivo.open("datos.txt");

    while(getline(archivo, linea)){
        cout << linea << endl;
    }

    archivo.close();

    return 0;
}
