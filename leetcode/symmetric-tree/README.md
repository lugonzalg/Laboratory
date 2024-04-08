101. Symmetric Tree
Easy
Topics
Companies

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    -100 <= Node.val <= 100

 
Follow up: Could you solve it both recursively and iteratively?

Algoritmo:

Literalmente utilizar el algoritmo de same_tree pero con los nodos izq y derecha

MALA IMPLEMENTACION

Algoritmo2: (respuesta de leetcode)

cumple el mismo requisito que el algoritmo de same tree, pero para este caso, en vez de ser exactamente iguales compara que esten en modo espejo.

por lo que no hay que comparar los nodos en el mismo orden si no en orden inverso. izq y der por der e izq.

                        1
                    2   |    2
                3      4|4       3
                       ...

Para el fondo del arbol el algoritmo se resolveria de la siguiente forma:

return _is_same_tree(3, 3) and
    _is_same_tree(4, 4);

...

Comparando el nodo opuesto en cada nivel, para afirma la simetria.