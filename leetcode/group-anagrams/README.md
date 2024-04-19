49. Group Anagrams
Solved
Medium
Topics
Companies

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 

Constraints:

    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.


Analisis:

    Tengo que devolver conjunto de sublistas de anagramas. Segun lo que recuerdo, puedo ordenar las palabras en orden alfanumerico para poder saber en que subconjinto meter.

    Se me ocurre crear un hash_table de palabraas ordenadas, para poder meter cada anagrama en su subconjunto.

Algoritmo:

    anagramas init dict

    iterar palabras:
        ordenar palabra
        buscar en el diccionario
        añadir si existe o crear registro

    devolver valores