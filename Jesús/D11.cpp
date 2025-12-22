#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;


typedef unordered_map<string, vector<string>> Grafo;


long long contarCaminos(const string& actual, const string& destino, Grafo& g, unordered_map<string, long long>& memo) {
   
    if (actual == destino) return 1;

    if (memo.count(actual)) return memo[actual];

    long long total = 0;
    
    
    if (g.count(actual)) {
        for (const string& vecino : g.at(actual)) {
            total += contarCaminos(vecino, destino, g, memo);
        }
    }

    return memo[actual] = total;
}

int main() {
    ifstream archivo("input11.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir input11.txt" << endl;
        return 1;
    }

    Grafo grafo;
    string linea;

    
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        
        size_t pos_dos_puntos = linea.find(':');
        string origen = linea.substr(0, pos_dos_puntos);
        string destinos = linea.substr(pos_dos_puntos + 1);

        stringstream ss(destinos);
        string destino;
        while (ss >> destino) {
            grafo[origen].push_back(destino);
        }
    }

    archivo.close();

    
    unordered_map<string, long long> memo;

    
    long long resultado = contarCaminos("you", "out", grafo, memo);

    cout << "Número total de caminos de 'you' a 'out': " << resultado << endl;

    return 0;
}