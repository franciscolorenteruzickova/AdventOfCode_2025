Este problema fue seleccionado porque ofrece la oportunidad de trabajar 
con estructuras de grafos, recorridos en profundidad (DFS).

La solución se basa en modelar la cuadrícula de entrada como un grafo
dirigido, donde cada celda se representa mediante un nodo. Cada nodo almacena
su posición, su tipo ('.', 'S' o '^') y una lista de vecinos que representan
las posibles direcciones de propagación del rayo. Las reglas del problema se
traducen directamente en la construcción de las aristas del grafo: las celdas
normales ('.' y 'S') continúan el rayo hacia abajo, mientras que las celdas
tipo splitter ('^') generan dos bifurcaciones hacia abajo a la izquierda y a
la derecha.

El diseño del programa se ha estructurado utilizando clases para encapsular
el comportamiento. La clase Node representa una celda del tablero y encapsula
la información básica del nodo, mientras que la clase GridGraph se encarga de
construir el grafo, gestionar el recorrido y contabilizar los splits.

Una vez construido el grafo, se localiza el nodo inicial 'S' y se aplica un
recorrido DFS para visitar todos los nodos alcanzables desde dicho origen.
Para evitar visitar un mismo nodo más de una vez, se utiliza una matriz de
nodos visitados. Cada vez que el recorrido alcanza un nodo de tipo splitter
('^'), se incrementa el contador que registra el número total de divisiones
del rayo.

Se consideraron alternativas como el uso de BFS o la simulación directa del
rayo sin emplear grafos, pero estas opciones resultaban menos claras
conceptualmente y más difíciles de extender. La representación mediante
grafos y DFS proporciona una solución eficiente, clara y alineada con los
objetivos del ejercicio.

Desde un punto de vista personal, este trabajo ha permitido reforzar
conocimientos sobre grafos, recorridos en profundidad, encapsulación, diseño
orientado a objetos y gestión de memoria dinámica en C++, además de mostrar
cómo modelar problemas de propagación mediante estructuras algorítmicas
adecuadas.

El código debe incluir todos los ficheros necesarios para su ejecución (input,
tests, etc.). Para compilarlo:

g++ DIA7.cpp -o DIA7

Y para ejecutarlo:

./DIA7 FRESH.txt
