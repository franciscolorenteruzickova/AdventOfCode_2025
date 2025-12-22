//Comprovar si existe un patrón dentro de los IDs
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Devuelve true si n es inválido según la nueva regla
bool esRepetido(long long n) {
    string cad = to_string(n);
    int lon = cad.size();

    // Iterar solo sobre tamaños de bloque que dividen exactamente la longitud
    for (int tam = 1; tam <= lon / 2; tam++) {
        if (lon % tam == 0) {  // ahora no hay continue, solo bloques válidos
            string bloque = cad.substr(0, tam);
            bool valido = true;

            for (int i = tam; i < lon; i += tam) {
                if (cad.substr(i, tam) != bloque) {
                    valido = false;
                    break;
                }
            }

            if (valido) return true;
        }
    }

    return false;
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

    // Reemplazar comas por espacios
    for (char &c : linea)
        if (c == ',') c = ' ';

    string carc;
    stringstream inter(linea);
    long long suma = 0;

    while (inter >> carc) {
        size_t pos = carc.find('-');
        long long a = stoll(carc.substr(0, pos));
        long long b = stoll(carc.substr(pos + 1));

        for (long long n = a; n <= b; n++) {
            if (esRepetido(n)) {
                suma += n;
            }
        }
    }

    cout << "Suma total de IDs invalidos (Parte 2): " << suma << "\n";
    return 0;
}
