Este problema fue seleccionado porque permite aplicar técnicas de programación
dinámica. En particular, nos centra en maximizar la salida de bancos de baterías al
seleccionar un número fijo de dígitos de cada banco para formar el máximo
valor posible.

La solución se basa en representar cada banco de baterías como un objeto de
la clase BatteryBank, que encapsula la cadena de dígitos del banco y
proporciona un método maxJoltage(k) para calcular la subsecuencia máxima
de tamaño k mediante programación dinámica. La DP mantiene una tabla
dp[i][j] que representa el mejor número formado usando los primeros i
dígitos y eligiendo exactamente j de ellos. Así, cada dígito puede ser
omitido o usado, y se construyen progresivamente los máximos parciales hasta
obtener el valor máximo de k dígitos.

La clase BatteryFactory se encarga de gestionar todos los bancos de
baterías, almacenándolos en un vector y calculando la suma total de los
valores máximos de cada banco mediante el método totalMaxJoltage(k).

La programación dinámica es clave en este problema porque cada banco puede
tener muchos dígitos, y elegir los k mejores en orden requiere recordar
los máximos parciales de todas las longitudes posibles de subsecuencia.

Como alternativas, se podrían haber utilizado fuerza bruta, seleccionando
todas las combinaciones posibles de dígitos, o un enfoque voraz eligiendo
simplemente los dígitos más grandes, así como recursión simple. Todas estas
opciones resultan menos eficientes o incorrectas en algunos casos, por lo que
la programación dinámica garantiza una solución óptima y manejable.

El código debe incluir todos los ficheros necesarios para su ejecución (input,
tests, etc.). Para compilarlo:

g++ DIA3.cpp -o DIA3

Y para ejecutarlo:

./DIA3 VOLT.txt