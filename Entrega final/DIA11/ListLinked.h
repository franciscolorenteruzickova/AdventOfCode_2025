#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List<T> {
    private:
        Node<T>* first;
        int n;

        Node<T>* nodeAt(int pos) const {
            Node<T>* aux = first;
            for (int i = 0; i < pos; ++i) aux = aux->next;
            return aux;
        }

    public:
        ListLinked() : first(nullptr), n(0) {}
        
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
            n = 0;
        }
           
        T operator[] (int pos) {
            if (pos < 0 || pos >= n) throw out_of_range("Posición fuera de rango");
            return nodeAt(pos)->data;
        }

        friend ostream& operator<<(ostream &out, const ListLinked<T> &list) {
            out << "[";
            Node<T>* aux = list.first;
            for (int i = 0; i < list.n; i++) {
                out << aux->data;
                if (i < list.n - 1) out << ", ";
                aux = aux->next;
            }
            out << "]";
            return out;
        }
    
        friend ListLinked<T> operator+(const ListLinked<T>& l1, int n2) {
            ListLinked<T> res;
            Node<T>* aux = l1.first;
            while (aux != nullptr) {
                res.append(aux->data + n2);
                aux = aux->next;
            }
            return res;
        }

        void insert(int pos, T val) override {
            if (pos < 0 || pos > n) throw out_of_range("Posición fuera de rango");
            if (pos == 0) {
                first = new Node<T>(val, first);
            } else {
                Node<T>* prev = nodeAt(pos - 1);
                prev->next = new Node<T>(val, prev->next);
            }
            ++n;
        }

        void append(T e) override {
            if (first == nullptr) {
                first = new Node<T>(e);
            } else {
                Node<T>* cur = first;
                while (cur->next != nullptr) cur = cur->next;
                cur->next = new Node<T>(e);
            }
            ++n;
        }

        void prepend(T e) override {
            first = new Node<T>(e, first);
            ++n;
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) throw out_of_range("Posición fuera de rango");
            T value;
            if (pos == 0) {
                Node<T>* tmp = first;
                value = tmp->data;
                first = first->next;
                delete tmp;
            } else {
                Node<T>* prev = nodeAt(pos - 1);
                Node<T>* target = prev->next;
                value = target->data;
                prev->next = target->next;
                delete target;
            }
            --n;
            return value;
        }

        T get(int pos) const override {
            if (pos < 0 || pos >= n) throw out_of_range("Posición fuera de rango");
            Node<T>* cur = first;
            for (int i = 0; i < pos; ++i) cur = cur->next;
            return cur->data;
        }

        int search(T e) const override {
            Node<T>* cur = first;
            int idx = 0;
            while (cur != nullptr) {
                if (cur->data == e) return idx;
                cur = cur->next;
                ++idx;
            }
            return -1;
        }

        bool empty() const override {
            return n == 0;
        }

        int size() const override {
            return n;
        }
};

#endif
