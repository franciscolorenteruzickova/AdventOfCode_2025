#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream archivo("volt.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo volt.txt" << endl;
        return 1;
    }

    string banco;
    long long total = 0;

    while (getline(archivo, banco)) {
        int n = banco.size();
        
        if (n < 2) {
            throw runtime_error("Cada banco debe tener al menos dos dígitos");
        } else {
            // 
            vector<int> maxc2(n, -1);

            int best = -1;
            for (int i = n - 1; i >= 0; i--) {
                maxc2[i] = best;
                best = max(best, banco[i] - '0');
            }

            int maxi = 0;

            // 
            for (int i = 0; i < n; i++) {
                int c1 = banco[i] - '0';
                int c2 = maxc2[i];

                if (c2 >= 0) {
                    int volts = c1 * 10 + c2;
                    maxi = max(maxi, volts);
                }
            }

            total += maxi;
        }
    }

    cout << "Voltaje total: " << total << endl;
    return 0;
}
