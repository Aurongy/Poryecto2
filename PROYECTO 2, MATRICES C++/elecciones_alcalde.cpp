#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {

    const int districts = 5;
    const int candidates = 4;
    vector<string> candidateNames = {"A", "B", "C", "D"};
    int votes[districts][candidates] = {
        {194, 48, 206, 45};
        {180, 20, 320, 16};
        {221, 90, 140, 20};
        {432, 50, 821, 14};
        {820, 61, 946, 18};
    };

    // a) Imprimir la tabla con cabeceras
    cout << setw(10) << "Distrito";
    cout << setw(10) << "Candidato A"; 
    cout << setw(10) << "Candidato B";
    cout << setw(10) << "Candidato C"; 
    cout << setw(10) << "Candidato D" << endl;

    for (int i = 0; i < districts; ++i) {
        cout << setw(10) << (i + 1);
        for (int j = 0; j < candidates; ++j) {
            cout << setw(10) << votes[i][j];
        }
        cout << endl;
    }

    // b) Calcular y mostrar el total de votos por candidato
    int totalVotes[candidates] = {0};
    int overallVotes = 0;

    for (int i = 0; i < districts; ++i) {
        for (int j = 0; j < candidates; ++j) {
            totalVotes[j] += votes[i][j];
            overallVotes += votes[i][j];
        }
    }

    cout << "\nTotal de votos por candidato:\n";
    for (int j = 0; j < candidates; ++j) {
        double percentage = (static_cast<double>(totalVotes[j]) / overallVotes) * 100;
        cout << "Candidato " << candidateNames[j] << ": ";
        cout << totalVotes[j] << " votos (" << fixed << setprecision(2);
        cout << percentage << "%)\n";
    }

    // Determinar el candidato más votado
    int maxVotes = totalVotes[0];
    int winnerIndex = 0;

    for (int j = 1; j < candidates; ++j) {
        if (totalVotes[j] > maxVotes) {
            maxVotes = totalVotes[j];
            winnerIndex = j;
        }
    }

    cout << "Candidato más votado: Candidato " << candidateNames[winnerIndex];
    cout << " con " << totalVotes[winnerIndex] << " votos.\n";

    // c) Comprobar si hay un ganador
    double fiftyPercent = overallVotes * 0.5;

    if (totalVotes[winnerIndex] > fiftyPercent) {
        cout << "El candidato " << candidateNames[winnerIndex] 
        cout << " ha ganado con más del 50% de los votos.\n";
    } else {
        // d) Encontrar los dos candidatos más votados
        int first = 0, second = 1;

        // Asegurar que first tiene más votos que second
        if (totalVotes[second] > totalVotes[first]) {
            swap(first, second);
        }

        for (int j = 2; j < candidates; ++j) {
            if (totalVotes[j] > totalVotes[first]) {
                second = first;
                first = j;
            } else if (totalVotes[j] > totalVotes[second]) {
                second = j;
            }
        }

        cout << "Los candidatos que pasan a la segunda ronda son: Candidato ";
        cout << candidateNames[first] << " y Candidato ";
        cout << candidateNames[second] << ".\n";
    }

    return 0;
}
