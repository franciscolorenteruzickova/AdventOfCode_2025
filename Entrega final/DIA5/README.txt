Este problema fue seleccionado porque ofrece la oportunidad de implementar 
árboles binarios para gestionar rangos solapados y realizar búsquedas de 
pertenencia de manera eficiente.

La solución se basa en modelar cada rango de IDs frescos como un nodo en un
árbol binario de búsqueda. Cada nodo almacena un rango [inicio, fin] y
referencias a sus hijos izquierdo y derecho, representando los rangos menores
y mayores respectivamente. La inserción de un nuevo rango en el árbol sigue
reglas claras: si el rango está completamente a la izquierda o a la derecha
del nodo actual, se inserta en el hijo correspondiente; si se solapa con el
rango del nodo actual, se fusiona extendiendo los límites del rango.

La clase RangeNode encapsula la información de cada nodo y proporciona
métodos para insertar rangos y verificar si un ID pertenece a algún rango.
La clase IngredientTree actúa como contenedor del árbol, proporcionando
una interfaz clara para agregar rangos y consultar IDs frescos sin exponer
la estructura interna del árbol.

El programa lee el archivo de entrada, separando la sección de rangos frescos
de la sección de IDs disponibles, y va insertando los rangos en el árbol
binario. Luego, para cada ID disponible, se verifica si pertenece a algún
rango fresco utilizando la búsqueda descendente en el árbol. Esto permite
manejar eficientemente rangos muy grandes sin necesidad de expandirlos en
memoria, asegurando que cada consulta se realice en tiempo logarítmico en
promedio.

Se optó por esta representación mediante árbol binario frente a alternativas
como tablas hash o listas lineales debido a que:

Permite gestionar rangos que se pueden solapar y fusionar automáticamente.

Mantiene consultas rápidas para IDs disponibles sin recorrer todos los
rangos.

Proporciona una estructura de datos limpia y orientada a objetos, fácil
de mantener y ampliar.

Desde un punto de vista de aprendizaje, este ejercicio refuerza conceptos de
árboles binarios, fusión de rangos, búsqueda eficiente, y diseño de clases
en C++. La implementación final es clara, modular y permite escalar a
bases de datos de ingredientes mucho mayores.

El código debe incluir todos los ficheros necesarios para su ejecución (input,
tests, etc.). Para compilarlo:

g++ DIA5.cpp -o DIA5

Y para ejecutarlo:

./DIA5 ID.txt
