#include <iostream>
using namespace std;

class MathUtils {
public:
    // Método de clase: no requiere instancia
    static double square(double x);
    static double circleArea(double radio);
    static int    sign(double x);
    
    // Método de instancia: se requiere instancia
    double sumar(double n1, double n2);

    // Dato miembro de clase (compartido por todas las instancias)
    static constexpr double PI = 3.14159265358979;

	MathUtils() = default;

private:
    // Constructor privado → no se puede instanciar (patrón utility class)
    //MathUtils() = delete;
};


// La palabra 'static' NO se repite en la definición
double MathUtils::square(double x) {
    return x * x;
}

double MathUtils::circleArea(double radio) {
    return PI * radio * radio;   // acceso directo al miembro estático
}

int MathUtils::sign(double x) {
    if (x > 0) return  1;
    if (x < 0) return -1;
    return 0;
}

double MathUtils::sumar(double n1, double n2){
	return (n1 + n2);
}

int main(){
		
	cout << "4^2 = " << MathUtils::square(4) << endl;
	cout << "Area 1 = " << MathUtils::circleArea (3.5) << endl;
	
	MathUtils o;
	double m = o.sumar(3.0,5.5);
	cout << "3.0 + 5.5 = " << m;
	return 0;
	
}

