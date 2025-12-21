#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;


struct Punto {
    int r, c;
    bool operator<(const Punto& otro) const {
        if (r != otro.r) return r < otro.r;
        return c < otro.c;
    }
};

class Manifold {
private:
    vector<string> mapa;
    set<Punto> divisoresProcesados;
    int totalSplits = 0;
    int filas, columnas;

public:
    Manifold(const vector<string>& m) : mapa(m) {
        filas = m.size();
        columnas = m[0].size();
    }

    void lanzarRayo(int r, int c) {
       
        while (r < filas) {
            if (mapa[r][c] == '^') {
                Punto p = {r, c};
                if (divisoresProcesados.find(p) == divisoresProcesados.end()) {
                    divisoresProcesados.insert(p);
                    totalSplits++;
                    
                    if (c - 1 >= 0) lanzarRayo(r, c - 1);
                    if (c + 1 < columnas) lanzarRayo(r, c + 1);
                }
                return;
            }
            r++;         }
    }

    int getResultado() { return totalSplits; }
};

int main() {
    ifstream archivo("input7.txt");
    if (!archivo) {
        cerr << "Error al abrir input7.txt" << endl;
        return 1;
    }

    vector<string> lineas;
    string l;
    int startCol = -1;

    while (getline(archivo, l)) {
        if (l.empty()) continue;
        lineas.push_back(l);
       
        if (startCol == -1) {
            size_t pos = l.find('S');
            if (pos != string::npos) startCol = pos;
        }
    }

    Manifold simulador(lineas);
  
    simulador.lanzarRayo(0, startCol);

    cout << "El rayo se divide un total de: " << simulador.getResultado() << " veces." << endl;

    return 0;
}