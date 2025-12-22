Se ha empleado un arbol binario de intervalos (**Interval Tree**)

    5A.cpp - Programa principal que lee los intervalos, construye el árbol y calcula el resultado del primer reto.
    IntervalTree.h - Declaración de la estructura Interval (Struct), Node (Struct) y IntervalTree (Class).
    IntervalTree.cpp - Implementación completa del árbol de intervalos y sus operaciones.

### Intervalo: [min, max]
```cpp
    struct Interval{
        long long min;
        long long max;
    };
```

### Nodo
<img src="nodo.jpg"/>

```cpp
    struct Node{
        Interval i;
        long long maximum;
        Node *left, *right;
    };
```
