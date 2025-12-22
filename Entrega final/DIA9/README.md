# Advent of Code — Día 9
### Movie Theater · Custom Hash Table

## Resumen del problema

El objetivo es encontrar el rectángulo más grande que se puede formar utilizando dos puntos (baldosas rojas) del mapa como esquinas opuestas.


El área se calcula sumando 1 a las diferencias de las coordenadas para incluir las propias baldosas en las dimensiones:
$$Ancho = |x_1 - x_2| + 1$$
$$Alto = |y_1 - y_2| + 1$$

## Justificación de la técnica elegida

Para este problema, el uso de una Hash Table y un enfoque basado en coordenadas dispersas es la opción más eficiente por las siguientes razones:


**Densidad de datos y Busqueda eficiente:** Usamos una tabla hash porque crear una matriz tradicional (int grid[N][N]) consumiría mucha más memoria y se resolveria el problema de forma ineficiente. En cambio, la talba Hash facilita enormemente cualquier comprobación adicional de puntos específicos en tiempo constante $O(1)$.
Como solo una pequeña fracción de las celdas contiene puntos rojos. La Hash Table permite almacenar únicamente estos puntos, optimizando el uso de memoria de $O(Ancho \times Alto)$ a $O(N)$, donde $N$ es el número de puntos.



## Diseño y técnica utilizada

### 1. Representación del estado

Los puntos rojos se almacenan de dos formas complementarias:

- **Vector de estructuras Point:** Para permitir una iteración secuencial sencilla al comparar pares de puntos.
- **Hash Table propia:** Para organizar los puntos en memoria, gestionando las colisiones mediante encadenamiento (chaining) utilizando propia lista enlazada simplificada al usar solo la clase Node que apunta al siguiente elemento en el mismo índice de la tabla.

### 2. Implementación de la Hash Table

La clase HashTable ha sido diseñada desde cero para gestionar coordenadas:

**Función Hash robusta:** Combina $x$ e $y$ en un valor de 64 bits (long long) mediante desplazamientos de bits y operadores XOR para minimizar colisiones en el espacio 2D.

```cpp
int hashFunction(int x, int y) {
    unsigned long long k = ((unsigned long long)x << 32) ^ (unsigned int)y;
    return (k % m);
}
```

**Seguridad de memoria:** Implementa un destructor explícito que libera todos los nodos dinámicos creados con new, evitando fugas de memoria (memory leaks).

### 3. Lectura y extracción del input

El programa implementa una lectura robusta desde input.txt:

- Utiliza `getline` y `stringstream` para procesar cada línea
- Extrae las coordenadas ignorando caracteres de separación como comas
- Almacena los puntos en un vector para posterior procesamiento

### 4. Algoritmo de resolución

La lógica principal sigue estos pasos:

1. Se recorre el vector de puntos mediante dos bucles anidados para generar todos los pares únicos posibles ($i$ y $j$)
2. Para cada par, se asume que son esquinas opuestas de un rectángulo
3. Se calculan el ancho y el alto utilizando `llabs` para asegurar valores positivos y añadiendo el desfase de $+1$ exigido por el sistema de baldosas del problema
4. El área se calcula como `long long` para prevenir overflows (desbordamientos), ya que el producto de coordenadas grandes puede superar los 2,100 millones de un int estándar

## Complejidad

- **N:** Número de puntos rojos en el input
- **Tiempo:** $O(N^2)$ debido a la comparación de todos los pares de puntos
- **Espacio:** $O(N + M)$, donde $M$ es el tamaño de los buckets de la tabla hash

## Conclusión y reflexión 
 

Al implementar nuestra propia Hash Table, conseguimos una herramienta que maneja coordenadas de gran escala con un consumo de memoria mínimo, resolviendo el problema de forma instantánea.

Desde el punto de vista personal, este trabajo ha permitido reforzar
conocimientos sobre las tablas hash, recorridos en profundidad, diseño
orientado a objetos y gestión de memoria dinámica en C++, además de mostrar
cómo modelar problemas de propagación mediante estructuras algorítmicas
adecuadas.

## Complilar y ejecutar
El código debe incluir todos los ficheros necesarios para su ejecución (input,
dia9P1.cpp). Para compilarlo:

g++ -o dia9P1 dia9P1.cpp

Y para ejecutarlo:

./DIA9 input.txt
