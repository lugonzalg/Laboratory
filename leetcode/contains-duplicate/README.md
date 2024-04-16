217. Contains Duplicate
Solved
Easy
Topics
Companies

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109


Analisis:

    BRUTE FORCE:
        Tengo que buscar cualquier numero repetido en la lista. Brute force seria un bucle anidado, buscando para cada elemento un ocurrencia en la lista de numeros.

        Desde el numero i hasta n. Comparar todos los numeros i en otro bucle, con los numeros j.

        j es i + 1.
        n es la longitud de la lista.

    HASH MAP:

        Guardar los elementos en un Hash Map, para iterar una única vez la lista de números y comprobar si el numero existe en el Hash Map

Algoritmo:

    BRUTE FORCE:

        iterar lista desde i

            iterar lista desde i + 1
                lista[i] es igual a lista[j]
                    devolver ok
        devolver ko

    HASH MAP (dict):

        iterar nums:

            existe ocurrencia en el diccionario?
                devolver ok

        devolver ko

Replanteo:

    El programa no es el mas rapido, mirando las respuestas de leetcode, hay que utilizar un set. Los sets no permiten copias y son mas rapidos que un diccionario, he visto dos algoritmos:

        Analisis 1:

            Guardar los elementos en el set y comprobar si ya estan.

        Algoritmo 1:

            iterar numeros:

                está en el set?
                    devolver ok

                añadir al set
            
            devolver ko

        Analisis 2:
            comparar la longitud de la lista y el set. Como el set solo puede tener instancias unicas, en el momento que haya diferencia es que algún número está repetido.

        Algoritmo 2:

            la longitud de la lista es igual a la longitud del set?