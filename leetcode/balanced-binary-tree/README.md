110. Balanced Binary Tree
Easy
Topics
Companies

Given a binary tree, determine if it is
height-balanced
.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true

Algoritmo:

    Utilizar la funcion de max depth para izq y der desde root
    tenia mas complejidad. ERROR.

Algoritmo2: (leetcode solution)

    Calcula la profundidad de izq y der. Si no es mayor a 1.
    Se llama recursivamente con izq y der para hacer la misma comprobacion.