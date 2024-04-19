560. Subarray Sum Equals K
Medium
Topics
Companies
Hint

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

 

Constraints:

    1 <= nums.length <= 2 * 104
    -1000 <= nums[i] <= 1000
    -107 <= k <= 107


Analysis:

    SLIDING WINDOW - FAIL
        From a array return the number of subarrays. I Will use sliding window at first with left and right pointers.

        Start from 0 go to the end of the array with the right pointer until the k value is obtained or the array finished.

    SUM HASH TABLE:

        src: https://www.youtube.com/watch?v=fFVZt-6sgyo

        Create a prefix_sum hash table. Formula: prefix_sum - k = value
        using a variable iterate over the array, apply the formula to each iteration, check the hash_map if there is an equivalence add it to a count variable, otherwise create a register with the prefix_sum

Algorithm:

    SLIDING WINDOW - FAIL
        left = right = 0
        total = 0

        while right != end:            

            total += array[right]
            if total == k:
                count++
                right++
            elif total > k:
                total -= array[left]
                left++
            else:
                right++

    SUM HASH TABLE:

        prefix_sum = count = 0
        sum_table = {}

        iterate from 0 to n:

            prefix_sum += array[idx]
            formula value = prefix_sum - k
            if value in hash_table:
                add to count
            else
                increment prefix_sum record by 1