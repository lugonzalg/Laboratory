1. Two Sum
Solved
Easy
Topics
Companies
Hint

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

Analisis:

    Tengo que encontrar el valor 'target' en la lista.

    BRUTE FORCE:

        Iterar sobre todos los elementos y buscar el que da como resultado 'target'. Complejidad de tiempo O(n^2), complejidad de espacio O(0)

    HASH MAP:

        buscar en el hash map, el valor actual. Si existe, devolver los indices. Si no existe, guardar en el hash map, el resultado de 'target' - 'valor actual' como llave y el indice como valor. Complejidad de tiempo es O(n) y complejidad de espacio es O(n).

Algoritmo:

    BRUTE FORCE:

        len = longitud numeros.

        iterar numeros desde i = 0 < len:

            iterar numeros desde j = i + 1 < len:

                numero[i] == numero[j]
                    devolver i, j

    HASH_MAP:

        crear hash map

        iterar nums
            existe num?
                devolver indices
            guardar en target - num = indice