#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
 * Clase que representa un banco de baterías
 */
class BatteryBank {
private:
    string digits;  // Cadena de dígitos del banco

public:
    BatteryBank(const string& d) : digits(d) {}

    long long maxJoltage(int k) const {      // Calcula la subsecuencia máxima de tamaño k
        int n = digits.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));      // dp[i][j] = mejor número usando los primeros i dígitos con j dígitos elegidos
        
        for (int i = 0; i <= n; i++) {      // Inicialización: subsecuencia de tamaño 0 = 0
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            int d = digits[i - 1] - '0';
            for (int j = 0; j <= k; j++) {      // Omitir dígito actual
                dp[i][j] = dp[i - 1][j];
                if (j > 0 && dp[i - 1][j - 1] != -1) {      // Usar dígito actual
                    long long val = dp[i - 1][j - 1] * 10 + d;
                    dp[i][j] = max(dp[i][j], val);
                }
            }
        }

        return dp[n][k];
    }
};

/*
 * Clase que representa la fábrica de baterías
 */
class BatteryFactory {
private:
    vector<BatteryBank> banks;

public:
    void addBank(const string& line) {
        BatteryBank bank(line);
        banks.push_back(bank);
    }

    long long totalMaxJoltage(int k) const {        // Calcula la suma total de los máximos de todos los bancos con tamaño k
        long long total = 0;
        for (const auto& bank : banks) {
            total += bank.maxJoltage(k);
        }
        return total;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Uso: ./DIA3 archivo.txt\n";
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo\n";
        return 1;
    }

    BatteryFactory factory;
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            factory.addBank(line);
        }
    }
    file.close();

    int k = 12;  // Seleccionamos 12 baterias por banco
    long long total = factory.totalMaxJoltage(k);
    cout << "Suma total de máximos con " << k << " baterias: " << total << endl;

    return 0;
}
