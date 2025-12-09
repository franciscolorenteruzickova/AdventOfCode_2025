Este problema fue elegido porque permite aplicar y combinar varias técnicas
fundamentales de algoritmos. En concreto, nos ofrece la oportunidad de
implementar divide y vencerás mediante el algoritmo de ordenación MergeSort
para ordenar los rangos de IDs, y también divide y vencerás mediante la
búsqueda binaria para determinar si un ID pertenece a alguno de los rangos.

Se emplean principalmente técnicas de divide y vencerás: MergeSort ordena los
rangos por su límite inferior, garantizando eficiencia O(n log n), y la
búsqueda binaria verifica de manera eficiente si un ID pertenece a alguno de
los rangos fusionados, con coste O(log n) por consulta.

La resolución del problema se ha abordado de la siguiente manera: primero se
aplica MergeSort para ordenar los rangos por su límite inferior. A continuación,
se recorren todos los rangos ordenados y se combinan los que se superponen,
reduciendo el número total de intervalos a consultar. Por último, cada ID se
comprueba mediante búsqueda binaria en los rangos fusionados para determinar si
está “fresco”.

Se han considerado y descartado algunas alternativas, como el uso de otros
algoritmos de ordenación de mayor coste, o la comparación secuencial de cada ID
con todos los rangos, que resultaba demasiado ineficiente para grandes
conjuntos de datos. También se podría implementar un Interval Tree para
acelerar consultas dinámicas, pero en un escenario estático esto resulta
innecesario y aumenta la complejidad.

A nivel personal, se ha practicado el uso de técnicas de divide y vencerás,
como MergeSort y búsqueda binaria. Este problema refleja situaciones reales
de inventario y gestión de recursos, lo que lo hace significativo desde el
punto de vista práctico y de aprendizaje.

El código debe incluir todos los ficheros necesarios para su ejecución (input,
tests, etc.). Para compilarlo

g++ DIA5.cpp -o DIA5

Y para ejecutarlo:

./DIA5 ID.txt
