171. Excel Sheet Column Number
Easy
Topics
Companies

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

 

Example 1:

Input: columnTitle = "A"
Output: 1

Example 2:

Input: columnTitle = "AB"
Output: 28

Example 3:

Input: columnTitle = "ZY"
Output: 701

 

Constraints:

    1 <= columnTitle.length <= 7
    columnTitle consists only of uppercase English letters.
    columnTitle is in the range ["A", "FXSHRXW"].


Analisis:

    He aprendido a hacer este problema pero a la inversa.
    Hay que recorrer la string a la inversa con un exponente que multiplica por
    26 la letra, empezando desde 0.

Algoritmo:

    el total es, la suma de los exponentes 