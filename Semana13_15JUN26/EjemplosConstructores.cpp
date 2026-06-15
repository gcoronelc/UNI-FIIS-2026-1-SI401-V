/*
 * ============================================================================
 *  EjemplosConstructores.cpp
 * ----------------------------------------------------------------------
 *  Material académico — Constructores en C++
 *  Curso: Programación Orientada a Objetos (referencia conceptual)
 *  Autor: Material de apoyo elaborado para Gustavo Coronel
 * ----------------------------------------------------------------------
 *  Este archivo agrupa los casos más representativos del uso de
 *  constructores en C++:
 *
 *    1. Constructor por defecto (default constructor)
 *    2. Constructor parametrizado
 *    3. Constructor con argumentos por defecto
 *    4. Lista de inicialización de miembros (member initializer list)
 *    5. Constructor explícito (explicit) para evitar conversiones implícitas
 *    6. Constructores delegantes (delegating constructors, C++11)
 *    7. Constructor de copia (copy constructor)
 *    8. Constructor de movimiento (move constructor, C++11) — Regla de cinco
 *    9. Sobrecarga de constructores
 *   10. Constructores eliminados (= delete) y forzados (= default)
 *
 *  Compilación sugerida (g++):
 *    g++ -std=c++17 -Wall -Wextra -o ejemplos EjemplosConstructores.cpp
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>   // std::move
#include <stdexcept>

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
        std::cout << "[Punto] Constructor por defecto -> (0, 0)\n";
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

    void mostrar() const {
        std::cout << "Punto(" << x_ << ", " << y_ << ")\n";
    }
};

// ============================================================================
// 5: Constructor explicit — evita conversiones implícitas no deseadas
// ============================================================================
class Temperatura {
private:
    double celsius_;

public:
    // Sin "explicit", una función que reciba un Temperatura podría aceptar
    // accidentalmente un double (p. ej. calcularConfort(25.0)), generando
    // una conversión implícita Temperatura(25.0) no intencionada.
    explicit Temperatura(double celsius) : celsius_(celsius) {
        if (celsius_ < -273.15) {
            throw std::invalid_argument(
                "Temperatura por debajo del cero absoluto");
        }
    }

    double enCelsius() const { return celsius_; }
    double enFahrenheit() const { return celsius_ * 9.0 / 5.0 + 32.0; }
};

// ============================================================================
// 6: Constructores delegantes (C++11) — varios constructores que delegan
//    en uno "maestro" para evitar duplicar lógica de validación/inicialización
// ============================================================================
class Persona {
private:
    std::string nombre_;
    int edad_;
    std::string documento_;

public:
    // Constructor "maestro": contiene la lógica de validación.
    Persona(std::string nombre, int edad, std::string documento)
        : nombre_(std::move(nombre)), edad_(edad), documento_(std::move(documento)) {
        if (edad_ < 0 || edad_ > 120) {
            throw std::invalid_argument("Edad fuera de rango válido");
        }
        if (nombre_.empty()) {
            throw std::invalid_argument("El nombre no puede estar vacío");
        }
    }

    // Delegación: persona sin documento -> documento = "SIN_DOCUMENTO"
    Persona(std::string nombre, int edad)
        : Persona(std::move(nombre), edad, "SIN_DOCUMENTO") {
        std::cout << "[Persona] Construida sin documento\n";
    }

    // Delegación: persona "anónima" con edad 0
    explicit Persona(std::string nombre)
        : Persona(std::move(nombre), 0) {
        std::cout << "[Persona] Construida solo con nombre\n";
    }

    void mostrar() const {
        std::cout << "Persona{nombre=" << nombre_
                  << ", edad=" << edad_
                  << ", documento=" << documento_ << "}\n";
    }
};

// ============================================================================
// 7 y 8: Constructor de copia y constructor de movimiento (Regla de cinco)
//        Caso clásico: una clase que administra un recurso dinámico (RAII).
// ============================================================================
class BufferDinamico {
private:
    int* datos_;
    size_t tamano_;

public:
    // Constructor parametrizado: reserva memoria.
    explicit BufferDinamico(size_t tamano)
        : datos_(new int[tamano]), tamano_(tamano) {
        std::cout << "[BufferDinamico] Constructor: reservando "
                  << tamano_ << " enteros\n";
        for (size_t i = 0; i < tamano_; ++i) {
            datos_[i] = static_cast<int>(i);
        }
    }

    // (7) Constructor de copia: realiza una copia profunda (deep copy).
    //     Imprescindible cuando la clase gestiona memoria dinámica,
    //     pues el constructor de copia generado por el compilador
    //     haría una copia superficial (shallow copy) del puntero,
    //     provocando doble liberación (double free).
    BufferDinamico(const BufferDinamico& otro)
        : datos_(new int[otro.tamano_]), tamano_(otro.tamano_) {
        std::cout << "[BufferDinamico] Constructor de copia (deep copy)\n";
        std::copy(otro.datos_, otro.datos_ + tamano_, datos_);
    }

    // (8) Constructor de movimiento (C++11): "roba" el recurso del
    //     objeto temporal en lugar de copiarlo, y deja al original
    //     en un estado válido pero vacío. Mucho más eficiente cuando
    //     el objeto fuente es un temporal (rvalue) o se mueve explícitamente.
    BufferDinamico(BufferDinamico&& otro) noexcept
        : datos_(otro.datos_), tamano_(otro.tamano_) {
        std::cout << "[BufferDinamico] Constructor de movimiento\n";
        otro.datos_ = nullptr;
        otro.tamano_ = 0;
    }

    // Operador de asignación por copia (parte de la regla de cinco).
    BufferDinamico& operator=(const BufferDinamico& otro) {
        if (this != &otro) {
            int* nuevosDatos = new int[otro.tamano_];
            std::copy(otro.datos_, otro.datos_ + otro.tamano_, nuevosDatos);
            delete[] datos_;
            datos_ = nuevosDatos;
            tamano_ = otro.tamano_;
        }
        return *this;
    }

    // Operador de asignación por movimiento (parte de la regla de cinco).
    BufferDinamico& operator=(BufferDinamico&& otro) noexcept {
        if (this != &otro) {
            delete[] datos_;
            datos_ = otro.datos_;
            tamano_ = otro.tamano_;
            otro.datos_ = nullptr;
            otro.tamano_ = 0;
        }
        return *this;
    }

    // Destructor: libera el recurso (RAII).
    ~BufferDinamico() {
        std::cout << "[BufferDinamico] Destructor: liberando memoria"
                  << (datos_ ? "" : " (ya movido, nada que liberar)") << "\n";
        delete[] datos_;
    }

    size_t tamano() const { return tamano_; }

    void mostrar() const {
        std::cout << "BufferDinamico[ ";
        for (size_t i = 0; i < tamano_; ++i) {
            std::cout << datos_[i] << " ";
        }
        std::cout << "]\n";
    }
};

// ============================================================================
// 9: Sobrecarga de constructores en una misma clase (sin delegación,
//    para ilustrar la diferencia con el caso 6)
// ============================================================================
class Rectangulo {
private:
    double base_;
    double altura_;

public:
    // Constructor por defecto -> cuadrado unitario
    Rectangulo() : base_(1.0), altura_(1.0) {}

    // Constructor para cuadrado: un solo parámetro
    explicit Rectangulo(double lado) : base_(lado), altura_(lado) {}

    // Constructor general: base y altura distintas
    Rectangulo(double base, double altura) : base_(base), altura_(altura) {
        if (base <= 0 || altura <= 0) {
            throw std::invalid_argument("Las dimensiones deben ser positivas");
        }
    }

    double area() const { return base_ * altura_; }
};

// ============================================================================
// 10: Constructores = delete y = default
//     Útil para forzar políticas de diseño: por ejemplo, una clase que NO
//     debe poder copiarse (p. ej. representa un recurso único como un
//     manejador de conexión a base de datos).
// ============================================================================
class ConexionUnica {
private:
    std::string identificador_;

public:
    explicit ConexionUnica(std::string id) : identificador_(std::move(id)) {
        std::cout << "[ConexionUnica] Conexión '" << identificador_
                  << "' establecida\n";
    }

    // Se elimina explícitamente el constructor de copia y el operador
    // de asignación por copia: esta clase NO debe duplicarse.
    ConexionUnica(const ConexionUnica&) = delete;
    ConexionUnica& operator=(const ConexionUnica&) = delete;

    // Se permite (y se solicita explícitamente al compilador) mover la
    // conexión de un objeto a otro.
    ConexionUnica(ConexionUnica&&) = default;
    ConexionUnica& operator=(ConexionUnica&&) = default;

    ~ConexionUnica() {
        std::cout << "[ConexionUnica] Cerrando conexión '"
                  << identificador_ << "'\n";
    }
};

// ============================================================================
// main(): demostración de uso de cada caso
// ============================================================================
int main() {
    std::cout << "=== 1, 2, 3 y 4: Punto ===\n";
    Punto p1;               // (1) Constructor por defecto
    Punto p2(3.5, 7.2);     // (2) Constructor parametrizado
    Punto p3(5.0);          // (3) Constructor con y por defecto (delegante)
    p1.mostrar();
    p2.mostrar();
    p3.mostrar();
    std::cout << "\n";

    std::cout << "=== 5: Temperatura (explicit) ===\n";
    Temperatura t1(36.5);
    // Temperatura t2 = 40.0;   // <-- ERROR de compilación: gracias a
    //                              "explicit" se evita la conversión implícita
    //                              double -> Temperatura. Esto previene
    //                              errores donde se pasa por accidente un
    //                              double a una función que espera Temperatura.
    std::cout << "Temperatura en F: " << t1.enFahrenheit() << "\n\n";

    std::cout << "=== 6: Persona (constructores delegantes) ===\n";
    Persona per1("Gustavo Coronel", 30, "DNI-12345678");
    Persona per2("Estudiante Anonimo", 21);
    Persona per3("Visitante");
    per1.mostrar();
    per2.mostrar();
    per3.mostrar();
    std::cout << "\n";

    std::cout << "=== 7 y 8: BufferDinamico (copia vs movimiento) ===\n";
    BufferDinamico buf1(5);
    buf1.mostrar();

    std::cout << "-- Copiando buf1 en buf2 (deep copy) --\n";
    BufferDinamico buf2 = buf1;     // invoca constructor de copia
    buf2.mostrar();

    std::cout << "-- Moviendo buf1 a buf3 (move) --\n";
    BufferDinamico buf3 = std::move(buf1); // invoca constructor de movimiento
    buf3.mostrar();
    std::cout << "buf1 ahora tiene tamano = " << buf1.tamano()
              << " (recurso transferido)\n\n";

    std::cout << "=== 9: Rectangulo (constructores sobrecargados) ===\n";
    Rectangulo r1;            // 1x1
    Rectangulo r2(4.0);       // cuadrado 4x4
    Rectangulo r3(3.0, 6.0);  // rectángulo general
    std::cout << "Area r1 = " << r1.area() << "\n";
    std::cout << "Area r2 = " << r2.area() << "\n";
    std::cout << "Area r3 = " << r3.area() << "\n\n";

    std::cout << "=== 10: ConexionUnica (= delete / = default) ===\n";
    ConexionUnica con1("ORA19C-SESSION-01");
    // ConexionUnica con2 = con1;  // <-- ERROR de compilación: constructor
    //                                  de copia eliminado (= delete)
    ConexionUnica con2 = std::move(con1); // OK: constructor de movimiento

    std::cout << "\n=== Fin del programa ===\n";
    return 0;
}
