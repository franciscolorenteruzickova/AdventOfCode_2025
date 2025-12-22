#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long calcularMaximoBanco(const string& linea) {
    int maxVoltaje = -1;
    int n = linea.length();


    for (int i = 0; i < n - 1; ++i) {

        int decena = linea[i] - '0';

       
        for (int j = i + 1; j < n; ++j) {
            int unidad = linea[j] - '0';
            
       
            int voltajeActual = decena * 10 + unidad;

            if (voltajeActual > maxVoltaje) {
                maxVoltaje = voltajeActual;
            }
        }
    }
    return (maxVoltaje == -1) ? 0 : maxVoltaje;
}

int main() {
    ifstream archivo("input.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo input.txt" << endl;
        return 1;
    }

    string linea;
    long long sumaTotal = 0;

    
    while (getline(archivo, linea)) {
        if (linea.empty()) continue; 
        
        sumaTotal += calcularMaximoBanco(linea);
    }

    archivo.close();

    cout << "La suma total de los voltajes maximos es: " << sumaTotal << endl;

    return 0;
}