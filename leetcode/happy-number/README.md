202. Happy Number
Easy
Topics
Companies

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false

 

Constraints:

    1 <= n <= 231 - 1

Analisis:

    Lo primero que se me ocurre es hacer el proceso del cuadrado de los digitos hasta encontrar 1 o que el numero sea igual al comienzo.

    Con el modulo de 10 sacar el numero y sumarlo a la nueva variable, asi hasta que el numero actual sea 0.

    Comprobar si es igual o es 1. En ese caso devolver false y true respectivamente.

Algoritmo:

    new_val = 0
    exp = 0
    forever
        until n == 0
            new_val += power (n mod 10)
            n = n div 10
        
        condition new_val == n or new_val == 1:
            break

    return new_val equal 1

    El resultado es incorrecto aunque la idea en general era buena.

Algoritmo 2:

    Sigue exactamente el mismo principio, solo que se le añade la comprobación de que no sea ni 1 ni 4, porque 1 es el numero feliz y 4 se cicla sobre sí.

    src:  https://leetcode.com/problems/happy-number/solutions/4992320/c-done-easily-with-looping-0ms/