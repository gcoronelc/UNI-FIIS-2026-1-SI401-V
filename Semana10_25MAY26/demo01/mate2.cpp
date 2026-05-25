// ============================================================
// Programa: MiPrimeraClase.cpp
// Descripción: Ejemplo introductorio de clases en C++
// La clase guarda dos números enteros y puede
// calcular su suma y su producto.
// ============================================================

#include <iostream>   // Necesario para usar cout y cin
using namespace std;  // Nos permite escribir cout en vez de std::cout

// ============================================================
// DEFINICIÓN DE LA CLASE
// ============================================================

class OperacionesEnteras {

    // ---------------------------------------------------------
    // PRIVADO: solo la propia clase puede ver estos datos
    // (nadie de afuera puede cambiarlos directamente)
    // ---------------------------------------------------------
    private:
        int valorA;   // Primer número
        int valorB;   // Segundo número

    // ---------------------------------------------------------
    // PÚBLICO: estas funciones sí pueden usarlas desde afuera
    // ---------------------------------------------------------
    public:

		// --- CONSTRUCTOR ---
        // Se llama automáticamente al crear un objeto.
        // Su trabajo es guardar los dos números que recibe.
        OperacionesEnteras() {
            valorA = 20;   // Guarda el primer número
            valorB = 30;   // Guarda el segundo número
        } 
        
        // --- CONSTRUCTOR ---
        // Se llama automáticamente al crear un objeto.
        // Su trabajo es guardar los dos números que recibe.
        OperacionesEnteras(int a, int b) {
            valorA = a;   // Guarda el primer número
            valorB = b;   // Guarda el segundo número
        }
        
        // --- MÉTODO 1: obtener la suma ---
        // Devuelve la suma de los dos números guardados
        int obtenerSuma() {
            return valorA + valorB;
        }

        // --- MÉTODO 2: obtener el producto ---
        // Devuelve la multiplicación de los dos números guardados
        int obtenerProducto() {
            return valorA * valorB;
        }
        
        int getValorA(){
        	return valorA;
		}
			
		int getValorB(){
        	return valorB;
		}
		

}; // <-- No olvides este punto y coma al cerrar la clase

// ============================================================
// PROGRAMA PRINCIPAL
// ============================================================

int main() {

    // Paso 1: Crear un objeto llamado "op"
    // Le pasamos los dos números: 6 y 4
    OperacionesEnteras op;

    // Paso 2: Usar los métodos del objeto
    int suma     = op.obtenerSuma();
    int producto = op.obtenerProducto();

    // Paso 3: Mostrar los resultados
    cout << "Primer numero:  " << op.getValorA() << endl;
    cout << "Segundo numero: " << op.getValorB() << endl;
    cout << "--------------------------" << endl;
    cout << "Suma:     " << suma        << endl;
    cout << "Producto: " << producto    << endl;

    return 0;
}