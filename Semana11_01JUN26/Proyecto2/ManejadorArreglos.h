#include <iostream>
#include <vector>
using namespace std;

class ManejadorArreglos {
	
private:
    vector<int> arregloA;
    vector<int> arregloB;

    // Función auxiliar interna para eliminar duplicados de un vector
    //void eliminarDuplicados(vector<int>& vec);

	void printArreglo(vector<int>& vec, string etiqueta);
	
	bool existe(vector<int>& vec, int num);
	
public:
    // Constructor: Recibe el valor de N
    ManejadorArreglos(int N);

    // Métodos de instancia para resolver los requerimientos
    vector<int> obtenerComunes();      // Intersección sin duplicados
    vector<int> obtenerDiferencia();   // A - B sin duplicados
    vector<int> obtenerSuma();         // Suma posición a posición
    
    // Métodos para visualizar los resultados
    void mostrarArreglos();
};

ManejadorArreglos::ManejadorArreglos(int N){
	// Arreglo 1
	this->arregloA.push_back(10);
	this->arregloA.push_back(15);
	this->arregloA.push_back(30);
	this->arregloA.push_back(20);
	this->arregloA.push_back(10);
	this->arregloA.push_back(15);
	// Arreglo 2
	this->arregloB.push_back(10);
	this->arregloB.push_back(40);
	this->arregloB.push_back(25);
	this->arregloB.push_back(20);
	this->arregloB.push_back(30);
}

void ManejadorArreglos::printArreglo(vector<int>& vec, string etiqueta){
	cout << endl << etiqueta << endl;
	cout << "========================" << endl;
	cout << "Arreglo: ";
	for (int num : vec) {
        cout << num << "  ";
    }
    cout << endl;
}

void ManejadorArreglos::mostrarArreglos(){
	this->printArreglo(arregloA, "ARREGLO A");
	this->printArreglo(arregloB, "ARREGLO B");
}

bool ManejadorArreglos::existe(vector<int>& vec, int num){
	for (int x : vec) {
        if(x == num) 
			return true;
    }
	return false;	 
}

vector<int> ManejadorArreglos::obtenerComunes(){
	vector<int> comun;
	for (int x : arregloA) {
        if(this->existe(arregloB, x) && !this->existe(comun,x)) 
			comun.push_back(x);
    }
	return comun;
}

vector<int> ManejadorArreglos::obtenerDiferencia(){
	vector<int> dife;
	for (int x : arregloA) {
        if(!this->existe(arregloB, x) && !this->existe(dife,x)) 
			dife.push_back(x);
    }
	return dife;
}

vector<int> ManejadorArreglos::obtenerSuma(){
	vector<int> suma;
	int tope = (arregloA.size()>arregloB.size())?arregloA.size():arregloB.size();
	int s;
	for(int i = 0; i < tope; i++){
		s = 0;
		s += (i<arregloA.size())?arregloA[i]:0;
		s += (i<arregloB.size())?arregloB[i]:0;
		suma.push_back(s);
	}
	return suma;
}