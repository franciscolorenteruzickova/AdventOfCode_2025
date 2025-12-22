Este problema fue seleccionado porque ofrece la oportunidad de trabajar con estructuras de 
grafos y recorridos en profundidad. A diferencia de otros retos, este permite profundizar 
en el conteo de caminos y la optimización de algoritmos mediante técnicas de programación
dinámica.

La solución se basa en modelar la lista de dispositivos de entrada como un grafo dirigido 
acíclico, donde cada dispositivo se representa mediante un nodo.

->Modelado de nodos: Cada nodo almacena su identificador único (nombre del dispositivo)
 y una lista de vecinos que representan las conexiones de salida hacia otros dispositivos.

->Construcción de aristas: Las reglas del problema se traducen directamente en la
 construcción de las aristas: la salida de un dispositivo crea un enlace dirigido hacia el 
 siguiente.

->Estructuras STL: Se ha utilizado un std::unordered_map para implementar la lista de
 adyacencia, garantizando búsquedas eficientes de nodos.

El diseño del programa se ha estructurado utilizando un enfoque orientado a objetos.

->Encapsulación: Se emplea una clase para representar el grafo del reactor, gestionando la
 construcción de la red a partir del archivo de entrada y el proceso de búsqueda.

->Recorrido DFS: Una vez construido el grafo, se localiza el nodo inicial etiquetado como "you"
 y se aplica un recorrido en profundidad (DFS) para explorar todas las rutas posibles hasta el
 nodo "out".

->Memoización: Para optimizar la solución y evitar recalcular rutas ya exploradas desde un
 mismo nodo, se utiliza una estructura de almacenamiento para los resultados parciales. 
 
->Contabilización: Cada vez que el recorrido alcanza el nodo de destino, 
 se registra el camino encontrado, sumando el total de trayectorias únicas.

Se consideraron alternativas como la simulación de fuerza bruta sin almacenamiento de
estados, pero estas resultaban menos eficientes computacionalmente ante grafos complejos.