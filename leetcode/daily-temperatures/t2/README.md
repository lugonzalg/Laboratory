739. Daily Temperatures
Attempted
Medium
Topics
Companies
Hint

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

 

Constraints:

    1 <= temperatures.length <= 105
    30 <= temperatures[i] <= 100


Analisis:
    paso 1:
        llorar

    paso 2:
        Crear un max stack. No se si existe. Ale.
        Iterar la lista en orden inverso buscando el valor. 

    paso 3 neetcode solution:

        Guardar en stack las temperaturas. Cuando la temperatura con la que se compara en mayor, borrar el registro y añadir la nueva temperatura. Repetir el proceso hasta que el stack esté vacío o el registro en el stack sea mayor que el record.

        Cuando el registro es menor que la temperatura al comienzo del stack. Añadir registro.

Algoritmo:
    Mismo funcionamiento que min stack pero al con max.

    paso 2:

        iterar inveros. Guardar maximos en stack.

    paso 3 neetcode:

        Iterao todas las temperaturas.

            si el stack esta vacio añadir temperatura

            si el registro es mayor que el primer elemento del stack. Borrar registro, añadir el nuevo, añadir 1.

test:

    [73,74,75,71,69,72,76,73]

    Valores maximos en cada iteracion

    1 - [73,74,75,71,69,72,76,73]
        [73]

    2 - [73,74,75,71,69,72,76,73]
        [73, 74]

    3 - [73,74,75,71,69,72,76,73]
        [73, 74, 75]

    4 - [73,74,75,71,69,72,76,73]
        [73, 74, 75, 75]

    5 - [73,74,75,71,69,72,76,73]
        [73, 74, 75, 75]

    6 - [73,74,75,71,69,72,76,73]
        [73,74,75,75,75,75]

    7 - [73,74,75,71,69,72,76,73]
        [73,74,75,75,75,75,76]

    8 - [73,74,75,71,69,72,76,73]
        [76,76,76,76,76,76,76,73]
        [ 1, 1, 4, 2, 1, 1, 0, 0]