69. Sqrt(x)
Easy
Topics
Companies
Hint

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

Algorithm

Use something similar to binary search for find the neares lower number?

100 square root is 10, good.

First from 1 double each time until its power is bigger.

    1 (1) -> 2 (4) -> 4 (16) -> 8 (64) -> 16 (4096)

16 is bigger than 100 and 8 is lower than 100.

Start from the nearest option with the half of the increased value, for this is 8 which is the neares number, the half of the increased value is 4 (8 / 2).

So the next number is 12, which is bigger than 100, ... repeat the same process.

pseudo code:

 find_nearest(low, high, direction)

 Stop, first, simple algorithm, linear check.