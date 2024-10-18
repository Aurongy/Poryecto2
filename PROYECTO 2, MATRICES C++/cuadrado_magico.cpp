#include <iostream>
#include <vector>

using namespace std;

void printMagicSquare(const vector<vector<int>>& square) {
    int size = square.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j < size - 1) {
                cout << square[i][j] << "\t";
            } else {
                cout << square[i][j];
            }
        }
        cout << endl;
    }
}

void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n + 1, vector<int>(n + 1, 0));

    int row = 0;
    int col = n / 2; 

    for (int num = 1; num <= n * n; ++num) {
        magicSquare[row][col] = num;
        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        if (magicSquare[nextRow][nextCol] != 0) { 
            row = (row + 1) % n; 
        } else {
            row = nextRow; 
            col = nextCol;
        }
    }

    for (int i = 0; i < n; ++i) {
        magicSquare[i][n] = 0;
        for (int j = 0; j < n; ++j) {
            magicSquare[i][n] += magicSquare[i][j]; 
        }
    }

    for (int j = 0; j < n; ++j) {
        magicSquare[n][j] = 0; 
        for (int i = 0; i < n; ++i) {
            magicSquare[n][j] += magicSquare[i][j]; 
        }
    }

    // Calcular diagonales
    magicSquare[n][n] = 0; 
    for (int i = 0; i < n; ++i) {
        magicSquare[n][n] += magicSquare[i][i]; 
    }

    magicSquare[n][n] += 0; 
    for (int i = 0; i < n; ++i) {
        magicSquare[n][n] += magicSquare[i][n - 1 - i];
    }

    printMagicSquare(magicSquare);
}

int main() {
    int n;
    cout << "Ingrese un número impar entre 3 y 11: ";
    cin >> n;

    if (n < 3 || n > 11 || n % 2 == 0) {
        cout << "Por favor, ingrese un número impar válido entre 3 y 11." << endl;
        return 1;
    }

    generateMagicSquare(n);
    return 0;
}
