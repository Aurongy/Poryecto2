#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Equipo {
    int id;
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;
    int partidosJugados;
    int diferenciaGoles;
    int puntos;

    // Función para calcular los puntos del equipo
    void calcularPuntos() {
        puntos = partidosGanados * 3 + partidosEmpatados;
    }
};

void imprimirMatriz(const vector<Equipo>& equipos) {
    cout << left << setw(10) << "Equipo"
    cout << setw(15) << "PG"
    cout << setw(15) << "PE"
    cout << setw(15) << "PP"
    cout << setw(15) << "PJ"
    cout << setw(15) << "DG"
    cout << setw(15) << "Puntos" << endl;

    for (const auto& equipo : equipos) {
        cout << left << setw(10) << equipo.id
        cout << setw(15) << equipo.partidosGanados
        cout << setw(15) << equipo.partidosEmpatados
        cout << setw(15) << equipo.partidosPerdidos
        cout << setw(15) << equipo.partidosJugados
        cout << setw(15) << equipo.diferenciaGoles
        cout << setw(15) << equipo.puntos << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el número de equipos: ";
    cin >> n;

    vector<Equipo> equipos(n);

    // Entrada de datos
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese los datos para el equipo " << (i + 1) << ":\n";
        equipos[i].id = i + 1; // Asignar un ID al equipo
        cout << "Partidos ganados (PG): ";
        cin >> equipos[i].partidosGanados;
        cout << "Partidos empatados (PE): ";
        cin >> equipos[i].partidosEmpatados;
        cout << "Partidos perdidos (PP): ";
        cin >> equipos[i].partidosPerdidos;
        cout << "Diferencia de goles (DG): ";
        cin >> equipos[i].diferenciaGoles;
        equipos[i].partidosJugados = equipos[i].partidosGanados +
                                    equipos[i].partidosEmpatados +
                                    equipos[i].partidosPerdidos;

        // Calcular puntos
        equipos[i].calcularPuntos();
    }

    // Imprimir la matriz de resultados
    cout << "\nResultados del campeonato:\n";
    imprimirMatriz(equipos);

    // Determinar el equipo campeón
    int campeonIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (equipos[i].puntos > equipos[campeonIndex].puntos ||
            (equipos[i].puntos == equipos[campeonIndex].puntos &&
            (equipos[i].partidosGanados > equipos[campeonIndex].partidosGanados ||
            (equipos[i].partidosGanados == equipos[campeonIndex].partidosGanados &&
            equipos[i].diferenciaGoles > equipos[campeonIndex].diferenciaGoles)))) {
            campeonIndex = i;
        }
    }

    cout << "\nEl equipo campeón es el equipo " << equipos[campeonIndex].id
    cout << " con " << equipos[campeonIndex].puntos << " puntos." << endl;

    return 0;
}
