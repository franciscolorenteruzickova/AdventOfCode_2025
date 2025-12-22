#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

struct Node {
    Point p;
    Node* next;
};

class HashTable {
private:
    int m;
    vector<Node*> table;

    int hashFunction(int x, int y) {
        // Usando unsigned para manejar posible desbordamiento antes del módulo
        unsigned long long k = ((unsigned long long)x << 32) ^ (unsigned int)y;
        return (k % m);
    }

public:
    HashTable(int size) : m(size), table(size, nullptr) {}

    // Destructor para corregir la fuga de memoria
    ~HashTable() {
        for (int i = 0; i < m; i++) {
            Node* cur = table[i];
            while (cur) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }
    }

    void insert(int x, int y) {
        int idx = hashFunction(x, y);
        table[idx] = new Node{{x, y}, table[idx]};
    }
};

int main() {
    vector<Point> points;
    ifstream f("input.txt");

    if (!f) {
        cerr << "Could not open input.txt\n";
        return 1;
    }

    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        int x, y;
        char comma;
        stringstream ss(line);
        if (ss >> x >> comma >> y) {
            points.push_back({x, y});
        }
    }

    
    HashTable H(200003);
    for (auto& p : points) H.insert(p.x, p.y);

    long long maxArea = 0;

    // Comparación O(N^2) de todos los pares
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            // Calcular ancho y alto (incluidos los mosaicos mismos)
            long long width = llabs((long long)points[i].x - points[j].x) + 1;
            long long height = llabs((long long)points[i].y - points[j].y) + 1;
            
            long long area = width * height;
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    cout << "La area de un rectangulo más grande: " << maxArea << endl;
    return 0;
}