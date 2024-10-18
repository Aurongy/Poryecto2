#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NUM_VENDEDORES = 10;
const int NUM_MODELOS = 15;

int main() {
    // Nombres de los vendedores
    vector<string> vendedores(NUM_VENDEDORES);
    for (int i = 0; i < NUM_VENDEDORES; ++i) {
        vendedores[i] = "Vendedor " + to_string(i + 1);
    }

    // Matriz de ventas (vendedores x modelos)
    vector<vector<int>> ventas(NUM_VENDEDORES, vector<int>(NUM_MODELOS, 0));

    // Entrada de datos de ventas
    cout << "Ingrese las ventas mensuales (0 para finalizar):" << endl;
    for (int i = 0; i < NUM_VENDEDORES; ++i) {
        cout << "Ventas de " << vendedores[i] << ":\n";
        for (int j = 0; j < NUM_MODELOS; ++j) {
            cout << "Modelo " << j + 1 << ": ";
            cin >> ventas[i][j];
            if (ventas[i][j] < 0) {
                cout << "Por favor, ingrese un número no negativo." << endl;
                --j; // Volver a pedir el mismo modelo
            }
        }
    }

    // Cálculo de totales por vendedor y modelo
    vector<int> totalPorVendedor(NUM_VENDEDORES, 0);
    vector<int> totalPorModelo(NUM_MODELOS, 0);
    
    for (int i = 0; i < NUM_VENDEDORES; ++i) {
        for (int j = 0; j < NUM_MODELOS; ++j) {
            totalPorVendedor[i] += ventas[i][j];
            totalPorModelo[j] += ventas[i][j];
        }
    }

    // Imprimir informe de ventas
    cout << "\nInforme mensual de ventas:\n";
    cout << "-----------------------------------\n";
    cout << "Vendedor\t";
    for (int j = 0; j < NUM_MODELOS; ++j) {
        cout << "Modelo " << j + 1 << "\t";
    }
    cout << "Total\n";
    
    for (int i = 0; i < NUM_VENDEDORES; ++i) {
        cout << vendedores[i] << "\t";
        for (int j = 0; j < NUM_MODELOS; ++j) {
            cout << ventas[i][j] << "\t\t";
        }
        cout << totalPorVendedor[i] << endl;
    }

    cout << "-----------------------------------\n";
    cout << "Total por modelo:\n";
    for (int j = 0; j < NUM_MODELOS; ++j) {
        cout << "Modelo " << j + 1 << ": " << totalPorModelo[j] << endl;
    }

    // Determinar el mejor vendedor
    int mejorVendedorIndex = 0;
    for (int i = 1; i < NUM_VENDEDORES; ++i) {
        if (totalPorVendedor[i] > totalPorVendedor[mejorVendedorIndex]) {
            mejorVendedorIndex = i;
        }
    }

    cout << "El mejor vendedor es: " << vendedores[mejorVendedorIndex]
    cout << " con " << totalPorVendedor[mejorVendedorIndex] << " coches vendidos.\n";

    return 0;
}
