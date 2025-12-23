#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"
#include "ListLinked.h" 

using namespace std;

template <typename V>
class HashTable: public Dict<V> {
    private:
        int n;
        int max;
        ListLinked<TableEntry<V>> *table;
        
        int h(string key) const {
            unsigned long hash = 5381;
            for (char c : key) {
                hash = hash * 33 + c; 
            }
            return hash % max;
        }

    public: 
        HashTable(int size) : n(0), max(size) {
            table = new ListLinked<TableEntry<V>>[max];
        }
        
        ~HashTable() {
            delete[] table;
        }

        
        V& operator[](string key) { 
            int index = h(key);
            ListLinked<TableEntry<V>> &bucket = table[index]; 
            for (int i = 0; i < bucket.size(); ++i) {
                if (bucket.get(i).key == key) {
                    return bucket.getReference(i).value;
                }
            }
            
            insert(key, V());
            return operator[](key);
        }

        bool contains(string key) const {
            int index = h(key);
            ListLinked<TableEntry<V>> &bucket = table[index];
            for (int i = 0; i < bucket.size(); ++i) {
                if (bucket.get(i).key == key) return true;
            }
            return false;
        }
        
        void insert(string key, V value) override {
            int index = h(key);
            ListLinked<TableEntry<V>> &bucket = table[index];
            for (int i = 0; i < bucket.size(); ++i) {
                if (bucket.get(i).key == key) {
                    throw std::runtime_error("Clave ya existente"); 
                }
            }
            bucket.append(TableEntry<V>(key, value));
            ++n; 
        }
        
        V search(string key) const override { 
            int index = h(key);
            ListLinked<TableEntry<V>> &bucket = table[index];
            for (int i = 0; i < bucket.size(); ++i) {
                TableEntry<V> entry = bucket.get(i);
                if (entry.key == key) return entry.value;
            }
            throw std::runtime_error("Clave no encontrada"); 
        }
        
        V remove(string key) override {
            int index = h(key);
            ListLinked<TableEntry<V>> &bucket = table[index];
            for (int i = 0; i < bucket.size(); ++i) {
                if (bucket.get(i).key == key) {
                    V value = bucket.get(i).value;
                    bucket.remove(i);
                    --n;
                    return value;
                }
            }
            throw std::runtime_error("Clave no encontrada"); 
        }
        
        int entries() const override { return n; }
};
#endif
