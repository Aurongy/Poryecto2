#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_CHOFERES = 5;
const int DIAS_SEMANA = 6;

struct Chofer {
    string nombre;
    double horas[DIAS_SEMANA];
    double sueldoPorHora;
};

// Función para calcular el total de horas trabajadas
double calcularTotalHoras(const Chofer& chofer) {
    double total = 0;
    for (int i = 0; i < DIAS_SEMANA; ++i) {
        total += chofer.horas[i];
    }
    return total;
}

// Función para calcular el sueldo semanal
double calcularSueldoSemanal(const Chofer& chofer) {
    return calcularTotalHoras(chofer) * chofer.sueldoPorHora;
}

// Función para calcular el total a pagar por la empresa
double calcularTotalEmpresa(const vector<Chofer>& choferes) {
    double total = 0;
    for (const auto& chofer : choferes) {
        total += calcularSueldoSemanal(chofer);
    }
    return total;
}

// Función para encontrar al chofer que trabaja más horas el lunes
string choferMasHorasLunes(const vector<Chofer>& choferes) {
    int maxHoras = -1;
    string choferNombre;
    for (const auto& chofer : choferes) {
        if (chofer.horas[0] > maxHoras) {
            maxHoras = chofer.horas[0];
            choferNombre = chofer.nombre;
        }
    }
    return choferNombre;
}

// Función para imprimir el reporte
void imprimirReporte(const vector<Chofer>& choferes) {
    cout << left << setw(20) << "Nombre";
    cout << setw(15) << "Total Horas";
    cout << setw(15) << "Sueldo Semanal" << endl;
    cout << "----------------------------------------" << endl;
    
    for (const auto& chofer : choferes) {
        double totalHoras = calcularTotalHoras(chofer);
        double sueldoSemanal = calcularSueldoSemanal(chofer);
        cout << left << setw(20) << chofer.nombre;
        cout << setw(15) << totalHoras;
        cout << setw(15) << sueldoSemanal << endl;
    }
}

int main() {
    vector<Chofer> choferes(NUM_CHOFERES);

    // Entrada de datos
    for (int i = 0; i < NUM_CHOFERES; ++i) {
        cout << "Ingrese el nombre del chofer " << (i + 1) << ": ";
        cin >> choferes[i].nombre;
        cout << "Ingrese el sueldo por hora del chofer " << choferes[i].nombre << ": ";
        cin >> choferes[i].sueldoPorHora;
        cout << "Ingrese las horas trabajadas de " << choferes[i].nombre << " de Lunes a Sábado:\n";
        for (int j = 0; j < DIAS_SEMANA; ++j) {
            cout << "Día " << (j + 1) << ": ";
            cin >> choferes[i].horas[j];
        }
    }

    int opcion;
    do {
        cout << "\nMenú de Opciones:\n";
        cout << "1. Calcular total de horas trabajadas\n";
        cout << "2. Calcular sueldos semanales\n";
        cout << "3. Calcular total a pagar por la empresa\n";
        cout << "4. Trabajador que labora más horas el lunes\n";
        cout << "5. Imprimir reporte\n";
        cout << "6. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\nTotal de horas trabajadas por cada chofer:\n";
                for (const auto& chofer : choferes) {
                    cout << chofer.nombre << ": " << calcularTotalHoras(chofer) << " horas" << endl;
                }
                break;
            }
            case 2: {
                cout << "\nSueldo semanal de cada chofer:\n";
                for (const auto& chofer : choferes) {
                    cout << chofer.nombre << ": " << calcularSueldoSemanal(chofer) << " unidades monetarias" << endl;
                }
                break;
            }
            case 3: {
                cout << "\nTotal a pagar por la empresa: " << calcularTotalEmpresa(choferes) << " unidades monetarias" << endl;
                break;
            }
            case 4: {
                cout << "\nChofer que labora más horas el lunes: " << choferMasHorasLunes(choferes) << endl;
                break;
            }
            case 5: {
                imprimirReporte(choferes);
                break;
            }
            case 6: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción inválida. Por favor, elija de nuevo." << endl;
            }
        }
    } while (opcion != 6);

    return 0;
}
