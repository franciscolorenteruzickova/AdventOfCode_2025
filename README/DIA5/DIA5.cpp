#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 * Clase RangeNode: Nodo de un árbol binario que representa un rango de IDs frescos [start, end]
 */
class RangeNode {
public:
    long long start, end;  // Inicio y fin del rango
    RangeNode* left;
    RangeNode* right;

    RangeNode(long long s, long long e) : start(s), end(e), left(nullptr), right(nullptr) {}

    /*
     * Inserta un nuevo rango [s, e] en el árbol
     * Si el rango está completamente a la izquierda o derecha, se inserta en el hijo correspondiente
     * Si se solapa con este nodo, se fusiona (se expande el rango actual)
     */
    void insertRange(long long s, long long e) {
        if (e < start - 1) { // Rango completamente a la izquierda
            if (!left) {
                left = new RangeNode(s, e);
            } else {
                left->insertRange(s, e);
            }
        } else if (s > end + 1) { // Rango completamente a la derecha
            if (!right) {
                right = new RangeNode(s, e);
            } else {
                right->insertRange(s, e);
            }
        } else { // Rango solapado, entonces fusionar con este nodo
            start = min(start, s);
            end = max(end, e);
        }
    }

    /*
     * Verifica si un ID está dentro de este rango o en alguno de los hijos
     */
    bool contains(long long id) const {
        if (id >= start && id <= end) { // ID dentro de este rango
            return true;
        } else if (id < start && left) { // Buscar en hijo izquierdo
            return left->contains(id);
        } else if (id > end && right) { // Buscar en hijo derecho
            return right->contains(id);
        } else {
            return false;
        }
    }

    // Destructor recursivo para liberar memoria
    ~RangeNode() {
        delete left;
        delete right;
    }
};

/*
 * Clase IngredientTree: Árbol binario que representa la base de datos de ingredientes frescos
 */
class IngredientTree {
private:
    RangeNode* root;

public:
    IngredientTree() : root(nullptr) {}

    /*
     * Agrega un rango [s, e] al árbol
     */
    void addRange(long long s, long long e) {
        if (!root) {
            root = new RangeNode(s, e);
        } else {
            root->insertRange(s, e);
        }
    }

    /*
     * Verifica si un ID está dentro de algún rango fresco
     */
    bool isFresh(long long id) const {
        if (!root) {
            return false;
        } else {
            return root->contains(id);
        }
    }

    // Destructor para liberar memoria
    ~IngredientTree() {
        delete root;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Uso: ./DIA5 archivo.txt\n";
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo\n";
        return 1;
    }

    IngredientTree tree;   // Árbol para almacenar los rangos
    string line;
    bool readingRanges = true; // Bandera para saber si estamos leyendo rangos o IDs disponibles
    int freshCount = 0;        // Contador de IDs frescos encontrados

    while (getline(file, line)) {
        if (line.empty()) { // Línea vacía → cambiar a sección de IDs disponibles
            readingRanges = false;
            continue;
        }

        if (readingRanges) {
            size_t dash = line.find('-');
            long long s = stoll(line.substr(0, dash));
            long long e = stoll(line.substr(dash + 1));
            tree.addRange(s, e);
        } else {
            long long id = stoll(line);
            if (tree.isFresh(id)) {
                freshCount++;
            }
        }
    }
    file.close();

    // Mostrar resultado: cantidad de IDs frescos disponibles
    cout << "IDs frescos disponibles: " << freshCount << endl;

    return 0;
}
