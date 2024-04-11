203. Remove Linked List Elements
Easy
Topics
Companies

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

Analisis:

    Hay que borrar todos los nodos con el valor x.

Algoritmo:

    Recorrer linked list, si el nodo tiene el valor x borrar y asignar al anterior el siguiente.

    Hay dos casos que el valor este en el comienzo y que no este en el comienzo.

    Si esta al comienzo, simplemente borrar y adelantar la cabeza.
    Si no esta al comienzo.

    La idea estaba bien faltaban detalles. OKAY.