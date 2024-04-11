206. Reverse Linked List
Easy
Topics
Companies

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

Analisis:

    Tengo una linked list, hay que invertirla. Con un puntero temporal guardar el anterior elemento para asignar next al anterior. Utilizar una variable auxiliar para no perder referencias.


Algoritmo:

    variable temporal es null.
    auxiliar sin definir.

    Itero la lista.

        guardo en el auxiliar la siguiente referencia.
        el nodo actual apunta al temporal.
        el temporal se convierte en el nodo actual.
        seguir iterando desde el auxiliar.

    OK