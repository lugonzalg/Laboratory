22. Generate Parentheses
Solved
Medium
Topics
Companies

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

 

Constraints:

    1 <= n <= 8

Analysis:

    step 1:
        cry

    step 2:
        I remember doing this. It is recursive for sure. Okay.

        I have n which is the times I have to call the recursion for open parentheses.

        For each recursive call I have to decrement in 1 n when adding a open bracket.

Algortihm:

    helper function n input.copy

        if n add ( to input
            recursive n -1 input.copy
        else add ) to input
            recursive call

FAILED. Neetcode answer.        