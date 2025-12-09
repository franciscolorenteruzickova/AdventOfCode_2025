Este problema fue elegido porque permite aplicar y combinar varias técnicas
fundamentales de algoritmos. En concreto, nos ofrece la oportunidad de
implementar estructuras de grafos mediante nodos y vectores de adyacencia, y
también técnicas de recorrido de grafos usando DFS para analizar la propagación
y división de los rayos de tachyon.

Se emplean principalmente estructuras de grafos y técnicas de búsqueda en
profundidad: cada celda de la matriz se representa como un nodo, con vecinos
determinados por las reglas de propagación del rayo ('.' y 'S' continúan recto,
'^' genera bifurcaciones a izquierda y derecha). La DFS recorre todos los nodos
alcanzables desde el nodo inicial 'S' y contabiliza cada bifurcación como un
split, garantizando que cada nodo se visite exactamente una vez.

La resolución del problema se ha abordado de la siguiente manera: primero se
crea una matriz de nodos a partir de la entrada, donde cada nodo almacena su
posición, valor y vecinos. A continuación, se construyen las aristas de acuerdo
con las reglas de movimiento de los rayos. Después, se localiza el nodo inicial
'S' y se aplica DFS, manteniendo una matriz de nodos visitados para evitar
recorrer el mismo nodo varias veces. Cada vez que DFS encuentra un splitter
('^'), incrementa el contador de splits. Al final del recorrido, se obtiene el
número total de divisiones de los rayos en el laberinto.

Se han considerado y descartado alternativas como recorrer la matriz con BFS,
o simular explícitamente cada rayo sin usar grafos, pero esto resultaba más
complejo y menos eficiente para grandes diagramas. La representación mediante
nodos y vectores de vecinos permite un código más limpio y fácil de mantener.

A nivel personal, se ha practicado la implementación de estructuras de grafos,
recorridos DFS y manejo de memoria dinámica en C++. Este problema refleja
situaciones de simulación de sistemas físicos discretos y análisis de
propagación, lo que lo hace significativo desde el punto de vista práctico y de
aprendizaje.

El código debe incluir todos los ficheros necesarios para su ejecución (input,
tests, etc.). Para compilarlo:

g++ DIA7.cpp -o DIA7

Y para ejecutarlo:

./DIA7 FRESH.txt
