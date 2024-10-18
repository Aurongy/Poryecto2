#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void displayWord(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            cout << letter << ' ';
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> words = {"programacion", "ahorcado", "computadora", "algoritmo", "desarrollo"};
    srand(static_cast<unsigned int>(time(0))); // Inicializar la semilla para números aleatorios
    string selectedWord = words[rand() % words.size()]; // Seleccionar una palabra aleatoria
    vector<char> guessedLetters;
    int attempts = 6; // Número de intentos permitidos

    cout << "¡Bienvenido al juego del ahorcado!" << endl;

    while (attempts > 0) {
        cout << "Palabra: ";
        displayWord(selectedWord, guessedLetters);
        cout << "Letras adivinadas: ";
        for (char letter : guessedLetters) {
            cout << letter << ' ';
        }
        cout << endl;

        cout << "Intentos restantes: " << attempts << endl;

        char guess;
        cout << "Adivina una letra: ";
        cin >> guess;
        guess = tolower(guess); // Convertir a minúsculas

        // Comprobar si la letra ya fue adivinada
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "Ya adivinaste la letra '" << guess << "'." << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        // Verificar si la letra está en la palabra
        if (selectedWord.find(guess) == string::npos) {
            attempts--;
            cout << "Letra incorrecta." << endl;
        } else {
            cout << "¡Correcto!" << endl;
        }

        // Verificar si se ha adivinado la palabra
        if (isWordGuessed(selectedWord, guessedLetters)) {
            cout << "¡Felicidades! Adivinaste la palabra: " << selectedWord << endl;
            break;
        }
    }

    if (attempts == 0) {
        cout << "Se acabaron los intentos. La palabra era: " << selectedWord << endl;
    }

    return 0;
}
