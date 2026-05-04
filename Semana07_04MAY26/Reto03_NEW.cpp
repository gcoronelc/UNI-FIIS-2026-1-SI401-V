/**
 * ============================================================
 *  UNIVERSIDAD NACIONAL DE INGENIERÍA — Escuela de Sistemas
 *  Curso    : Programación I
 *  Reto 03  : Tabla de Amortización con Cuota de Capital Fija
 *
 *  Descripción:
 *    Calcula la tabla de amortización para un préstamo personal,
 *    usando cuota de capital constante y tasa mensual definida
 *    por nivel de riesgo crediticio (1 a 4).
 *
 *  Refactorización aplicada:
 *    - Eliminación de variables globales (encapsulamiento)
 *    - Sustitución de array dinámico por std::vector<CuotaDetalle>
 *    - Validación robusta de entradas
 *    - Constantes nombradas para tasas de interés
 *    - Separación de responsabilidades (SRP)
 *    - Sin memory leaks (RAII vía std::vector)
 *    - Documentación interna completa
 * ============================================================
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// ============================================================
//  CONSTANTES
// ============================================================

/**
 * Tasas de interés mensual según nivel de riesgo crediticio.
 * Índice 0 no se utiliza; los niveles válidos son 1 a 4.
 */
const float TASAS_RIESGO[] = { 0.0f, 0.015f, 0.028f, 0.040f, 0.060f };
const int   RIESGO_MIN     = 1;
const int   RIESGO_MAX     = 4;

// ============================================================
//  ESTRUCTURAS DE DATOS
// ============================================================

/**
 * Representa los datos de entrada del préstamo.
 */
struct DatosPrestamo {
    float capital;   // Monto del préstamo en soles
    int   meses;     // Plazo en meses
    int   riesgo;    // Nivel de riesgo: 1 (bajo) a 4 (alto)
};

/**
 * Representa la información de una cuota mensual en la tabla
 * de amortización.
 */
struct CuotaDetalle {
    int   numeroCuota;    // Número de cuota (1-based)
    float capitalSaldo;   // Capital pendiente al inicio del período
    float cuotaCapital;   // Porción amortizada del capital
    float cuotaInteres;   // Porción correspondiente al interés
    float cuotaTotal;     // Cuota total = capital + interés
};

// ============================================================
//  PROTOTIPOS DE FUNCIONES
// ============================================================

bool          leerDatos(DatosPrestamo& datos);
float         obtenerTasa(int riesgo);
vector<CuotaDetalle> calcularTabla(const DatosPrestamo& datos);
void          mostrarReporte(const DatosPrestamo& datos,
                             const vector<CuotaDetalle>& tabla);
void          limpiarBuffer();

// ============================================================
//  FUNCIÓN PRINCIPAL
// ============================================================

int main() {
    DatosPrestamo datos;

    if (!leerDatos(datos)) {
        cerr << "\nError: Datos inválidos. El programa finalizará.\n";
        return 1;
    }

    vector<CuotaDetalle> tabla = calcularTabla(datos);
    mostrarReporte(datos, tabla);

    return 0;
}

// ============================================================
//  IMPLEMENTACIÓN DE FUNCIONES
// ============================================================

/**
 * Limpia el buffer de entrada para evitar lecturas erróneas
 * en caso de entrada inválida.
 */
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Solicita y valida los datos del préstamo al usuario.
 *
 * @param datos  Referencia a la estructura donde se almacenan
 *               los valores ingresados.
 * @return true  si todos los datos son válidos; false en caso
 *               contrario.
 */
bool leerDatos(DatosPrestamo& datos) {
    cout << "\nLECTURA DE DATOS\n";
    cout << "=====================================\n";

    // --- Lectura y validación del capital ---
    cout << "Importe del préstamo (S/.): ";
    if (!(cin >> datos.capital) || datos.capital <= 0.0f) {
        limpiarBuffer();
        cerr << "Error: El capital debe ser un número positivo.\n";
        return false;
    }

    // --- Lectura y validación de los meses ---
    cout << "Número de meses (plazo)   : ";
    if (!(cin >> datos.meses) || datos.meses <= 0) {
        limpiarBuffer();
        cerr << "Error: El plazo debe ser un entero positivo.\n";
        return false;
    }

    // --- Lectura y validación del nivel de riesgo ---
    cout << "Nivel de riesgo (1=bajo, 2=moderado, 3=alto, 4=muy alto): ";
    if (!(cin >> datos.riesgo) ||
        datos.riesgo < RIESGO_MIN ||
        datos.riesgo > RIESGO_MAX)
    {
        limpiarBuffer();
        cerr << "Error: El nivel de riesgo debe estar entre "
             << RIESGO_MIN << " y " << RIESGO_MAX << ".\n";
        return false;
    }

    return true;
}

/**
 * Retorna la tasa de interés mensual correspondiente al nivel
 * de riesgo indicado.
 *
 * @param riesgo  Nivel de riesgo (1 a 4).
 * @return        Tasa mensual como fracción (ej. 0.015 = 1.5%).
 */
float obtenerTasa(int riesgo) {
    return TASAS_RIESGO[riesgo];
}

/**
 * Calcula la tabla de amortización completa para el préstamo.
 * Utiliza el método de cuota de capital constante (sistema
 * alemán o francés de capital fijo).
 *
 * Fórmulas aplicadas por período i:
 *   cuotaCapital[i] = capital / meses          (constante)
 *   cuotaInteres[i] = saldo[i] * tasa
 *   cuotaTotal[i]   = cuotaCapital + cuotaInteres
 *   saldo[i+1]      = saldo[i] - cuotaCapital
 *
 * @param datos  Estructura con capital, meses y riesgo.
 * @return       Vector con el detalle de cada cuota.
 */
vector<CuotaDetalle> calcularTabla(const DatosPrestamo& datos) {
    vector<CuotaDetalle> tabla;
    tabla.reserve(datos.meses);

    float tasa         = obtenerTasa(datos.riesgo);
    float cuotaCapital = datos.capital / datos.meses;
    float saldo        = datos.capital;

    for (int i = 0; i < datos.meses; i++) {
        CuotaDetalle cuota;
        cuota.numeroCuota  = i + 1;
        cuota.capitalSaldo = saldo;
        cuota.cuotaCapital = cuotaCapital;
        cuota.cuotaInteres = saldo * tasa;
        cuota.cuotaTotal   = cuota.cuotaCapital + cuota.cuotaInteres;

        tabla.push_back(cuota);

        saldo -= cuotaCapital;
    }

    return tabla;
}

/**
 * Imprime el encabezado y el detalle de la tabla de
 * amortización en formato tabular alineado.
 *
 * @param datos   Datos del préstamo (capital y tasa).
 * @param tabla   Vector con el detalle de cada cuota.
 */
void mostrarReporte(const DatosPrestamo& datos,
                    const vector<CuotaDetalle>& tabla)
{
    float tasa = obtenerTasa(datos.riesgo);

    cout << "\n\nREPORTE DE AMORTIZACIÓN\n";
    cout << "=====================================\n";
    cout << fixed << setprecision(2);
    cout << "Capital prestado : S/. " << datos.capital   << "\n";
    cout << "Plazo            : "     << datos.meses     << " meses\n";
    cout << "Tasa mensual     : "     << tasa * 100.0f   << "%\n";
    cout << "Nivel de riesgo  : "     << datos.riesgo    << "\n";
    cout << "-------------------------------------\n";

    // Encabezado de la tabla
    cout << setw(7)  << "CUOTA"
         << setw(12) << "SALDO"
         << setw(12) << "C.CAPITAL"
         << setw(12) << "C.INTERES"
         << setw(12) << "C.TOTAL"
         << "\n";
    cout << string(55, '-') << "\n";

    // Detalle por cuota
    for (const CuotaDetalle& c : tabla) {
        cout << setw(7)  << c.numeroCuota
             << setw(12) << c.capitalSaldo
             << setw(12) << c.cuotaCapital
             << setw(12) << c.cuotaInteres
             << setw(12) << c.cuotaTotal
             << "\n";
    }

    cout << string(55, '=') << "\n";
}