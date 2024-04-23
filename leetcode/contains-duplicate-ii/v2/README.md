219. Contains Duplicate II
Solved
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

    Tengo que encontrar si hay algun valor donde nums[i] == nums[j] y |i - j| <= k

    He intentado utilizar sliding window pero acaba siendo n^2. Utilizando un hash_map puede ser n

Algoritmo:


