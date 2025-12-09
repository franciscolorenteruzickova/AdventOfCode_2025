#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//F MergeSort para ordenar los intervalos
void merge(vector<pair<long long, long long>> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<long long,long long>> L(n1);
    vector<pair<long long,long long>> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<pair<long long,long long>> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
// Fusión de los intervalos para reducir la cantidad de comparaciones
int newRange(vector<pair<long long,long long>> &ranges) {
    if (ranges.empty()) {
        return 0;
    }

    int idx = 0;
    for (int i = 1; i < ranges.size(); i++) {
        if (ranges[idx].second < ranges[i].first - 1) {
            idx++;
            ranges[idx] = ranges[i];
        } else {
            ranges[idx].second = max(ranges[idx].second, ranges[i].second);
        }
    }
    return idx + 1;
}
// Encontrar si un ID está dentro de algún intervalo usando búsqueda binaria
bool searchID(const vector<pair<long long,long long>> &ranges, int size, long long id) {
    int l = 0, r = size - 1;
    int pos = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (ranges[mid].first <= id) {
            pos = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return (pos != -1 && id <= ranges[pos].second);
}

int main() {
    vector<pair<long long,long long>> ranges;
    vector<long long> ids;

    ifstream file("ID.txt");
    if (!file) {
        cerr << "No se pudo abrir ID.txt" << endl;
        return 1;
    }

    string line;

    // Leemos los intervalos
    while (getline(file, line)) {
        if (line.empty()) { 
            break;
        }
        long long pr, sc;
        char gio;
        stringstream ss(line);
        ss >> pr >> gio >> sc;
        ranges.push_back({pr, sc});
        
    }

    // Leemos los IDs
    while (getline(file, line)) {
        if (!line.empty()) {;
        ids.push_back(stoll(line));
        }
    }

    file.close();

    // Ordenar los intervalos
    if (!ranges.empty())
        mergeSort(ranges, 0, ranges.size() - 1);

    int newSize = newRange(ranges);

    // Contar IDs frescos
    int idsCount = 0;
    for (long long id : ids) {
        if (searchID(ranges, newSize, id)) idsCount++;
    }

    cout << idsCount << endl;
    return 0;
}
