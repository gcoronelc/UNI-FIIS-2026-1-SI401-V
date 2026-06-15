#include <iostream>
using namespace std;

// ============================================================================
// 1, 2 y 3: Constructor por defecto, parametrizado y con argumentos
//           por defecto — Lista de inicialización (caso 4)
// ============================================================================

class Punto {
private:
    double x_;
    double y_;

public:
    // (1) Constructor por defecto: inicializa el objeto en el origen.
    //     Se usa una lista de inicialización (4), preferible a asignar
    //     dentro del cuerpo del constructor porque inicializa los
    //     miembros directamente (más eficiente y obligatorio para
    //     const/referencias).
    Punto() : x_(0.0), y_(0.0) {
        std::cout << "[Punto] Constructor por defecto -> (" << this->x_ << "," << this->y_ << ")\n";
        this->setX(1000);
    }

    // (2) Constructor parametrizado.
    Punto(double x, double y) : x_(x), y_(y) {
        std::cout << "[Punto] Constructor parametrizado -> ("
                  << x_ << ", " << y_ << ")\n";
    }

    // (3) Constructor con argumento por defecto: si solo se pasa "x",
    //     "y" se asume 0.0. Cuidado: no debe coexistir con una sobrecarga
    //     que genere ambigüedad (ver advertencia más abajo en main()).
    explicit Punto(double x) : Punto(x, 0.0) {
        // (6) Este constructor delega en Punto(double, double).
        std::cout << "[Punto] Constructor delegante con y=0 por defecto\n";
    }

    double getX() const { return x_; }
    double getY() const { return y_; }
    
    void setX(int x){
    	this->x_ = x;
	}

    void mostrar() const {
        std::cout << "Punto(" << x_ << ", " << y_ << ")\n";
    }
};


int main(){
	
	// Constructor por defecto.
	cout << "\nConstructor por defecto\n";
	Punto p1;
	p1.mostrar();
	
	// Constructor con parametros
	cout << "\nConstructor con parametros\n";
	Punto p2(3,4);
	p2.mostrar();
	
	// Constructor con argumento por defecto
	cout << "\nConstructor con argumento por defecto\n";
	Punto p3(5);
	p3.mostrar();

	
	
	return 0;
}