#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream archivo("rollos.txt");  // Cambia por tu nombre de archivo
    if (!archivo) {
        cerr << "No se puede abrir el archivo" << endl;
        return 1;
    }

    vector<string> cuadricula;
    string fila;

    // Leer todas las filas y guardarlas en el vector
    while (getline(archivo, fila)) {
        cuadricula.push_back(fila);
    }
    archivo.close();

    int totalrollos = 0;

    // Arrays para desplazamientos de los 8 vecinos
    int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

    // Recorrer cada casilla de la cuadrícula
    for (int i = 0; i < cuadricula.size(); i++) {
        for (int j = 0; j < cuadricula[i].size(); j++) {
            if (cuadricula[i][j] == '@') {
                int vecinos = 0;

                // Contar los rollos adyacentes
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    // Verificar límites
                    if (ni >= 0 && ni < cuadricula.size() &&
                        nj >= 0 && nj < cuadricula[i].size()) {
                        if (cuadricula[ni][nj] == '@') {
                            vecinos++;
                        }
                    }
                }

                // Si hay menos de 4 rollos alrededor, es accesible
                if (vecinos < 4) {
                    totalrollos++;
                }
            }
        }
    }

    cout << "Total de rollos accesibles: " << totalrollos << endl;

    return 0;
}
