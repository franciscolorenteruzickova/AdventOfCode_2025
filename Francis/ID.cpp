// Encontrar los IDs inválidos aquellos que se repiten así mismos
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Devuelve true si n es de la forma TT (dos bloques iguales)
bool esDoble(long long n) {
    string cad = to_string(n);
    int lon = cad.size();

    // Debe tener longitud par
    if (lon % 2 != 0) return false;

    string partea = cad.substr(0, lon/2);
    string parteb = cad.substr(lon/2);

    return (partea == parteb);
}

int main() {
    ifstream archivo("id.txt");
    if (!archivo) {
        cout << "No se pudo abrir id.txt\n";
        return 1;
    }

    string linea;
    getline(archivo, linea);
    archivo.close();
    // Reemplazar comas por espacios para facilitar lectura
    for (char &c : linea)
        if (c == ',') c = ' ';

    string carc;
    stringstream inter(linea);

    long long suma = 0;

    // Leer cada rango a-b
    while (inter >> carc) {
        size_t pos = carc.find('-');
        long long a = stoll(carc.substr(0, pos));
        long long b = stoll(carc.substr(pos + 1));

        // Recorrer el rango
        for (long long n = a; n <= b; n++) {
            if (esDoble(n)) {
                suma += n;
            }
        }
    }

    cout << "Suma total de IDs invalidos: " << suma << "\n";
    return 0;
}
