108. Convert Sorted Array to Binary Search Tree
Easy
Topics
Companies

Given an integer array nums where the elements are sorted in ascending order, convert it to a
height-balanced
binary search tree.

 

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in a strictly increasing order.


Problema:

Desde un array desordenado, crear un arbol binario balanceado (BST).

Tareas:

    1. Ordenar el array
    2. Crear el arbol binario

1. Ordenar el array:

    Utilizar la funcion sort de C++

2. Crear el arbol binario:

    Para una lista como 1 2 3 4 5 6 7 8 9 10 11

    primera capa -> la mediana es 6 que es igual a la longitud del array / 2

    1 2 3 4 5 6 7 8 9 10 11
      | | |   m1|   |  |
      | m2|     |   m3 |
      m4  m5    m6     m7

    Crear una funcion que busca la mediana.
    si end - start < 2, acabar y devolver el nodo.