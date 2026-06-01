#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fichero("Agenda.txt");
    bool encontrado = false;
    int lc, ln, i, j;
    string nombre, cadena, subcadena;

    cout << "Ingresar nombre a buscar en la agenda: ";
    getline(cin, nombre);
    ln = nombre.length();

    for (i = 0; i < ln; i++)
        nombre[i] = toupper(nombre[i]);

    while (!fichero.eof()) {
        getline(fichero, cadena);
        lc = cadena.length();

        for (i = 0; i < lc; i++)
            cadena[i] = toupper(cadena[i]);

        i = 0;
        j = 0;
        subcadena = "";

        while (i < lc) {
            if (cadena[i] == nombre[j]) {
                subcadena = subcadena + cadena[i];
                j++;
            } else {
                if (subcadena == nombre) {
                    encontrado = true;
                    j = 0;
                    i = lc;
                    subcadena = "";
                    cout << cadena << endl;
                } else {
                    j = 0;
                    subcadena = "";
                }
            }
            i++;
        }
    }

    fichero.close();

    if (!encontrado)
        cout << "No encontrado" << endl;

    return 0;
}