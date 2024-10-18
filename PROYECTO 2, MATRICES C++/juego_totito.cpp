#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const char PLAYER = 'X';
const char COMPUTER = 'O';
const char EMPTY = ' ';

void drawBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----\n";
    }
}

bool checkWinner(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void computerMove(vector<vector<char>>& board) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != EMPTY);
    board[row][col] = COMPUTER;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, EMPTY));
    int row, col;
    srand(static_cast<unsigned int>(time(0)));

    cout << "Bienvenido al juego de Tres en Raya\n";
    drawBoard(board);

    while (true) {
        cout << "Introduce tu movimiento (fila y columna): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY) {
            cout << "Movimiento invalido. Intenta de nuevo.\n";
            continue;
        }

        board[row][col] = PLAYER;
        drawBoard(board);

        if (checkWinner(board, PLAYER)) {
            cout << "Felicidades, ganaste\n";
            break;
        }

        if (isBoardFull(board)) {
            cout << "Es un empate\n";
            break;
        }

        computerMove(board);
        drawBoard(board);

        if (checkWinner(board, COMPUTER)) {
            cout << "La computadora gano. Mejor suerte la proxima vez\n";
            break;
        }

        if (isBoardFull(board)) {
            cout << "Es un empate\n";
            break;
        }
    }

    return 0;
}
