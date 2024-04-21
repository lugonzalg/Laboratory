20. Valid Parentheses
Solved
Easy
Topics
Companies
Hint

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

Analisis:

    paso 1:

        utilizando una lista. Añadir a la lista todos los parentesis de abertura.

        En caso de ser de clausura, sacar el ultimo elemento, si no hace match devolver error.

        Al final comprobar que el stack esta vacio.


Algoritmo:

    paso 1:

        stack

        iterar todos los elemtos:

            es de apertura?
                guardar

            es de clausura?
                sacar primer elemento
                comprobar que el match sea correcto

        esta la lista vacia?