875. Koko Eating Bananas
Solved
Medium
Topics
Companies

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

 

Constraints:

    1 <= piles. 104
    piles.length <= h <= 109
    1 <= piles[i] <= 109

Analysis:

    I remember doing this, so let's refresh. I have to find the lowest value capable of eating all piles in h iterations.

    the start value is the minimun value between the array length and h.

Algorithm:

    while low <= high

        

test:

    [3,6,7,11]

    Cuando come 4 cada vez.

        0 - [3,6,7,11]
        1 - [0,6,7,11]
        2 - [0,2,7,11]
        3 - [0,0,7,11]
        4 - [0,0,3,11]
        5 - [0,0,0,11]
        6 - [0,0,0,7]
        7 - [0,0,0,3]
        8 - [0,0,0,0]
            