#include <iostream>
using namespace std;

// ============================================================================
// 6: Constructores delegantes (C++11) — varios constructores que delegan
//    en uno "maestro" para evitar duplicar lógica de validación/inicialización
// ============================================================================
class Persona {
private:
    string nombre_;
    int edad_;
    string documento_;

public:
    // Constructor "maestro": contiene la lógica de validación.
    Persona(string nombre, int edad, string documento)
        : nombre_(std::move(nombre)), edad_(edad), documento_(std::move(documento)) {
        if (edad_ < 0 || edad_ > 120) {
            throw invalid_argument("Edad fuera de rango válido");
        }
        if (nombre_.empty()) {
            throw invalid_argument("El nombre no puede estar vacío");
        }
    }

    // Delegación: persona sin documento -> documento = "SIN_DOCUMENTO"
    Persona(std::string nombre, int edad)
        : Persona(move(nombre), edad, "SIN_DOCUMENTO") {
        cout << "[Persona] Construida sin documento\n";
    }

    // Delegación: persona "anónima" con edad 0
    explicit Persona(std::string nombre)
        : Persona(move(nombre), 0) {
        std::cout << "[Persona] Construida solo con nombre\n";
    }

    void mostrar() const {
        std::cout << "Persona{nombre=" << nombre_
                  << ", edad=" << edad_
                  << ", documento=" << documento_ << "}\n";
    }
};


int main(){
	
	Persona p1("Gustavo Coronel", 60, "55557777");
	p1.mostrar();
	
	cout << endl << endl;
	
	Persona p2("Gustavo Coronel", 50);
	p2.mostrar();
	
	cout << endl << endl;
	
	Persona p3("");
	p3.mostrar();
	
	
	
}
