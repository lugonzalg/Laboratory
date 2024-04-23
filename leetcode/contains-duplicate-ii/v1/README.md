219. Contains Duplicate II
Easy
Topics
Companies

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
    0 <= k <= 105

Analisis:

    Utilizar el metodo de 'sliding window'. Es un bucle anidado para buscar si se cumple nums[i] == nums[j] y abs(i - j) <= k

Algoritmo:

    complejidad de tiempo O(n^2)

    iterador i
        iterador empieza como j = i + 1

            j distinto de i
                volver

            calculo correct?
                ok

    ko

    LIMITE DE TIEMPO SUPERADO.

    hmmmmm

Analisis 2:

    No puedo buscar los elementos dos veces. 

    Guardar los indices de cada numero en un vector?

    no, es mucho mas facil TT src: https://leetcode.com/problems/contains-duplicate-ii/solutions/2727290/c-easy-detailed-explaination-optimized/

    Un mapa de numero indice. Guardar para cada numero su ultimo indice.
    