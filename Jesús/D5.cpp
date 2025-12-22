#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// rango [inicio, fin]
struct Rango {
    long long inicio;
    long long fin;
};

int main() {
    ifstream archivo("input5.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo input5.txt" << endl;
        return 1;
    }

    vector<Rango> listaRangos;
    string linea;

 
    while (getline(archivo, linea) && !linea.empty()) {
        Rango r;
        
        size_t guionPos = linea.find('-');
        if (guionPos != string::npos) {
            r.inicio = stoll(linea.substr(0, guionPos));
            r.fin = stoll(linea.substr(guionPos + 1));
            listaRangos.push_back(r);
        }
    }


    int contadorFresh = 0;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        long long idActual = stoll(linea);
        bool esFresh = false;


        for (const auto& r : listaRangos) {
            if (idActual >= r.inicio && idActual <= r.fin) {
                esFresh = true;
                break; 
            }
        }

        if (esFresh) {
            contadorFresh++;
        }
    }

    archivo.close();

    cout << "Número de ingredientes frescos: " << contadorFresh << endl;

    return 0;
}