#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
 * Clase que representa una celda del tablero
 * Cada nodo conoce su posición, valor y vecinos
 */
class Node {
public:
    int fila, col;
    char valor;
    vector<Node*> vecinos; // Lista de nodos adyacentes

    Node(int f, int c, char v) : fila(f), col(c), valor(v) {}

    bool isSplit() const {
        return valor == '^';
    }
};

/*
 * Clase que representa el grafo del laberinto y gestiona el recorrido
 * Creación del los nodos
 * Construcción de las aristas
 * Búsqueda del nodo inicial
 * Recorrido DFS
 * Conteo de splits
 */
class GridGraph {
private:
    vector<vector<Node*>> nodes;
    vector<vector<bool>> visitado;
    int filas, cols;
    int splits;

    // Marca los nodos visitados y cuenta los splitters encontrados
    void dfs(Node* node) {
        if (!node) return; // Caso base nodo nulo o ya visitado
        if (visitado[node->fila][node->col]) return;

        visitado[node->fila][node->col] = true; // Marca como visitado

        if (node->isSplit()) {
            splits++;
        }

        for (Node* vecino : node->vecinos) {
            dfs(vecino);
        }
    }

    // Construye las aristas según el tipo de cada celda
    void buildEdges() {
        for (int r = 0; r < filas; r++) {
            for (int c = 0; c < cols; c++) {
                Node* n = nodes[r][c];
                
                if (n->valor == '.' || n->valor == 'S') { // Las celdas normales continúan el rayo hacia abajo
                    if (r + 1 < filas) {
                        n->vecinos.push_back(nodes[r + 1][c]);
                    }
                } else if (n->valor == '^') { // Si es un splitter, se generan la bifurcación
                    if (r + 1 < filas && c - 1 >= 0) {
                        n->vecinos.push_back(nodes[r + 1][c - 1]);
                    }
                    if (r + 1 < filas && c + 1 < cols) {
                        n->vecinos.push_back(nodes[r + 1][c + 1]);
                    }
                }
            }
        }
    }

    // Busca el nodo inicial 'S'
    Node* findStart() {
        for (int r = 0; r < filas; r++) {
            for (int c = 0; c < cols; c++) {
                if (nodes[r][c]->valor == 'S') {
                    return nodes[r][c];
                }
            }
        }
        return nullptr;
    }

public:
    // Constructor: recibe la matriz de entrada y crea los nodos y construye el grafo
    GridGraph(const vector<string>& mat) {
        filas = mat.size();
        cols = mat[0].size();
        splits = 0;

        visitado.assign(filas, vector<bool>(cols, false));  // Inicializa la matriz de visitados
        nodes.assign(filas, vector<Node*>(cols, nullptr)); // Inicializa la matriz de nodos

        for (int r = 0; r < filas; r++) { // Crear nodos
            for (int c = 0; c < cols; c++) {
                nodes[r][c] = new Node(r, c, mat[r][c]);
            }
        }

        buildEdges(); // Construir las aristas
    }

    // Método público: cuenta los splits
    int countSplits() {
        Node* start = findStart();
        if (start) {
            dfs(start);
        }
        return splits;
    }

    // Destructor: libera memoria
    ~GridGraph() {
        for (int r = 0; r < filas; r++) {
            for (int c = 0; c < cols; c++) {
                delete nodes[r][c];
            }
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Uso: ./DIA7 archivo.txt\n";
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo\n";
        return 1;
    }

    vector<string> mat;
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            mat.push_back(line);
        }
    }

    file.close();

    if (mat.empty()) {
        cout << "El archivo está vacío\n";
        return 1;
    }

    GridGraph graph(mat);
    cout << "Total splits: " << graph.countSplits() << endl;

    return 0;
}
