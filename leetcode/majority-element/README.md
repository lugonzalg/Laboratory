169. Majority Element
Easy
Topics
Companies

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

 

Constraints:

    n == nums.length
    1 <= n <= 5 * 104
    -109 <= nums[i] <= 109

Analysis:

    I have to find the mayority number, which is the number that apprears n / 2 time, where n is the length of the array.

Algorithm:

    Create a unordered_map to store the quantity of appeareances, when a number hits the magic number return that number

    DONE, there are better methods, for now beyond my knowledge.