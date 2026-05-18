#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int promedio;
int mayor;
int menor;
bool existe; 

bool existeArchivo(string nombre){
	ifstream archivo(nombre);
    if(archivo){
    	archivo.close();
        return true;
    }
    return false;
}

vector<string> split(string texto, char separador){
    vector<string> datos;
    stringstream ss(texto);
    string temp;
    while(getline(ss, temp, separador)){
        datos.push_back(temp);
    }
    return datos;
}
void procesar(string nombre){
	
	existe = existeArchivo(nombre);
	if(!existe){
		return;
	}
	
	ifstream archivo;
    string linea;
    char simbolo = '|';
    vector<string> arreglo;
    int suma = 0;
    int cont = 0;
    int t;

    archivo.open(nombre);
	mayor = 0;
	menor = 20;
    while(getline(archivo, linea)){
    	if(linea.find(simbolo) == string::npos) continue;
    	cont++;
        arreglo = split(linea, simbolo);
        t = stoi(arreglo[1]);
        suma = suma + t;
        if(t < menor) menor = t;
        if(t > mayor) mayor = t;
    }

    archivo.close();
	
	promedio = suma / cont;
}

void agregarResumen(string nombre){
	ofstream archivo;
    archivo.open(nombre, ios::app);
	archivo << endl;
	archivo << "RESUMEN" << endl;
    archivo << "Nota promedio: " << promedio<< endl;
    archivo << "Nota mayor: " << mayor << endl;
    archivo << "Nota menor: " << menor << endl;

    archivo.close();
}

int main(){

    string nombre = "LP.txt";
	
	procesar(nombre);
	agregarResumen(nombre);
	
	
	cout << "Promedio: " << promedio << endl;
	cout << "Mayor: " << mayor << endl;
	cout << "Menor: " << menor << endl;
    return 0;
}