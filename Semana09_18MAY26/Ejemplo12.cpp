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

    archivo.open(nombre);

    while(getline(archivo, linea)){
    	if(linea.find(simbolo) == string::npos) continue;
    	cont++;
        arreglo = split(linea, simbolo);
        suma = suma + stoi(arreglo[1]);
    }

    archivo.close();
	
	promedio = suma / cont;
}



int main(){

    string nombre = "LP.txt";
	
	procesar(nombre);
	
	if(!existe){
		cout << "Archivo no existe!!\n";
		return -1;
	}
	
	cout << "Promedio: " << promedio << endl;
    return 0;
}