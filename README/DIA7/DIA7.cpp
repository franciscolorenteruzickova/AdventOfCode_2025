#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Estructura de nodo
struct Node {
    int fila, col;
    char valor;               // '.', 'S' o '^'
    vector<Node*> vecinos;  // nodos a los que puede ir el rayo
};

// DFS usando vector de visitados
void dfs(Node* node, vector<vector<bool>>& visitado, int& splits) {
    if (!node) {
        return;
    }

    if (visitado[node->fila][node->col]) {
        return; // ya visitado
    }
    visitado[node->fila][node->col] = true;

    if (node->valor == '^') {
        splits++; // contar split
    }

    for (Node* vecino : node->vecinos) {
        dfs(vecino, visitado, splits);
    }
}

int main() {
    vector<string> mat;
    string line;

    ifstream file("FRESH.txt");
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo FRESH.txt\n";
        return 1;
    }

    while (getline(file, line)) {
        if (!line.empty()) {
        mat.push_back(line);
        }
    }

    file.close();

    int fila = mat.size();
    if (fila == 0) {
        cout << "El archivo está vacío.\n";
        return 1;
    }

    int cols = mat[0].size();

    // Crear nodos
    vector<vector<Node*>> nodes(fila, vector<Node*>(cols, nullptr));
    for (int r = 0; r < fila; r++) {
        for (int c = 0; c < cols; c++) {
            nodes[r][c] = new Node{r, c, mat[r][c]};
        }
    }

    // Crear aristas
    for (int r = 0; r < fila; r++) {
        for (int c = 0; c < cols; c++) {
            Node* node = nodes[r][c];
            if (node->valor == '.' || node->valor == 'S') {
                if (r + 1 < fila) node->vecinos.push_back(nodes[r + 1][c]);
            } else if (node->valor == '^') {
                if (r + 1 < fila && c - 1 >= 0) node->vecinos.push_back(nodes[r + 1][c - 1]);
                if (r + 1 < fila && c + 1 < cols) node->vecinos.push_back(nodes[r + 1][c + 1]);
            }
        }
    }

    // Buscar nodo inicial 'S'
    Node* prim = nullptr;
    for (int r = 0; r < fila && !prim; r++) {
        for (int c = 0; c < cols; c++) {
            if (mat[r][c] == 'S') {
                prim = nodes[r][c];
                break;
            }
        }
    }

    if (!prim) {
        cout << "No se encontró 'S' en la cuadrícula.\n";
        return 1;
    }

    vector<vector<bool>> visitado(fila, vector<bool>(cols, false));
    int splits = 0;

    dfs(prim, visitado, splits);

    cout << "Total splits: " << splits << endl;

    // Liberar memoria
    for (int r = 0; r < fila; r++) {
        for (int c = 0; c < cols; c++) {
            delete nodes[r][c];
        }
    }
    return 0;
}
