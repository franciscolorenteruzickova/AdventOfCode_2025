//Mismo código que Password.cpp pero contando cuántas veces se cruza el 0

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: programa input.txt\n";
        return 1;
    }

    ifstream archivo(argv[1]);
    if (!archivo) {
        cerr << "No se pudo abrir " << argv[1] << "\n";
        return 1;
    }

    string s;
    int pos = 50;
    int contzero = 0;

    while (archivo >> s) {
        char dir = s[0];
        int dist = stoi(s.substr(1));

        int actual = pos;
        int ultima;
        if (dir == 'L') {
            ultima = (pos - dist) % 100; // Nueva posición
            if (ultima < 0) {
                ultima += 100; 
            }
            // Contar cuántas veces se cruza 0 al girar a la izquierda
            for (int i = 1; i <= dist; ++i) {
                int aux = (actual - i) % 100; // Posición intermedia
                if (aux < 0) {
                    aux += 100;
                }
                if (aux == 0) {
                    contzero++;
                }
            }
        } else { // R
            ultima = (pos + dist) % 100; // Nueva posición

            // Contar cuántas veces se cruza 0 al girar a la derecha
            for (int i = 1; i <= dist; ++i) {
                int aux = (actual + i) % 100;
                if (aux == 0) {
                    contzero++;
                }
            }
        }

        pos = ultima; // Actualizar posición

        // Ya contaste el 0 si se terminó la rotación ahí
        // (en este bucle ya se cuenta automáticamente)
    }

    cout << contzero << endl;
}
