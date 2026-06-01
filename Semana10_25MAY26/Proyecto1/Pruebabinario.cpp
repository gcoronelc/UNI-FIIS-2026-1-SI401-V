#include <iostream>
#include <fstream>
using namespace std;struct reg_agenda {
char nombre[30];
char direccion[50];
char telefono[10];
};int main() {
reg_agenda ragenda;
ofstream archi("Agenda.dat", ios::app | ios::binary);
if (!archi) {
cout << "No se pudo abrir el archivo." << endl;
return 1;
}
// Ejemplo de ingreso de datos
cout << "Ingrese nombre: ";
cin.getline(ragenda.nombre, 30);
cout << "Ingrese direccion: ";
cin.getline(ragenda.direccion, 50);
cout << "Ingrese telefono: ";
cin.getline(ragenda.telefono, 10);
// Escribir el registro en el archivo binario
archi.write(reinterpret_cast<char*>(&ragenda), sizeof(reg_agenda));
archi.close();
cout << "Registro guardado en archivo binario." << endl;
return 0;
}