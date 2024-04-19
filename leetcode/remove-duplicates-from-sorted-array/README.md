26. Remove Duplicates from Sorted Array
Solved
Easy
Topics
Companies
Hint

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

    Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
    Return k.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}

If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

 

Constraints:

    1 <= nums.length <= 3 * 104
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.

Analysis:

    step 1:

        iterate over the numbers starting from pos 1. If the element behind is equal to the current, put the front number in the current place.

    try 2:

        with two pointer starting from 0 and 1 respectively. I will increase the value of the pointer looking for a value that is not an exact copy of the integer pointed by the left pointer. When that is archieved I move the left pointer.

    try 3:

        keep it simple. left pointer position where to put a unique value. Right pointer looks for the unique value.

Algorithm:

    step 1:

        iterate from 1 to n -1:

            if currPos == currPos - 1:
                currPos = nextPos

    try 2:

        n = len
        left = 0
        right = n

        iterate until right = n:
            if 

    try 3:

        iterate over array:

            if left != right
                left = right
                left++
                unqiue++
            right++
        return unique