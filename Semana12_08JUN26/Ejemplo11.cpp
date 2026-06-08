// Funciones que modifican arreglos

#include <iostream>

using namespace std;

class Nodo {
	
public:
	
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
    
};

class Lista {
	
private:
	
    Nodo* cabeza;

public:
	
    Lista() {
        cabeza = nullptr;
    }

    // Método para agregar un nodo al final de la lista
    void agregarNodo(int valor) {
    	
        Nodo* nuevoNodo = new Nodo(valor);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            return;
        } 
         Nodo* actual = cabeza;
         while (actual->siguiente != nullptr) {
             actual = actual->siguiente;
         }
         actual->siguiente = nuevoNodo;
        
    }

    // Método para imprimir la lista
    void imprimirLista() {
    	
    	if(cabeza == nullptr){
    		cout << "Lista vacia.\n";
			return;
		}
    	
		Nodo* actual = cabeza;
		
		while (actual != nullptr) {
		   cout << actual->dato << " -> ";
		   actual = actual->siguiente;
		}
		
		cout << "NULL" << endl;
    }

    // Destructor para liberar la memoria utilizada
    ~Lista() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* temporal = actual;
            actual = actual->siguiente;
            delete temporal;
        }
    }
};

int main() {
    Lista lista;

    lista.agregarNodo(10);
    lista.agregarNodo(20);
    lista.agregarNodo(30);
    lista.agregarNodo(40);

    cout << "Contenido de la lista:" << std::endl;
    lista.imprimirLista();

    return 0;
}









