
// Contar cuantos ceros hay en la secuencia del vector circular al moverse a derecha y izquierda

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
        cerr << "No se pude abrir " << argv[1] << "\n";
        return 1;
    }

    string s;
    int pos = 50, contzero = 0;
    while (archivo >> s) {
        char dir = s[0];
        int dist = stoi(s.substr(1));
            if (dir == 'L' ) {
                pos = (pos - dist) % 100;
                if (pos < 0) pos += 100;
            } else {
                pos = (pos + dist) % 100;
            } 
        if (pos == 0) {
            contzero++;
        }
    }

    cout << contzero << endl;
}
