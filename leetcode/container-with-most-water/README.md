11. Container With Most Water
Solved
Medium
Topics
Companies
Hint

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

 

Constraints:

    n == height.length
    2 <= n <= 105
    0 <= height[i] <= 104

Analisis:

    step 1:

        I have to find two points in the array where the offset times the minimun heght is the maximun area.

        I have an idea. lets start from left and right. In a grid of 5 elements for example like: 1,2,3,4,2

        left pointer is in 1 and right pointer is in 2.

        the area is (end - start) * min(end_height, start_height)
        
        After calculation I just have to move the lower pointer, repeat until both pointers meet.

Algorithm:

    step 1:

        n = heights.len
        left = 0, right = n -1
        ans = 0

        while left != right:

            area = (height[right] - height[left]) * min(height[right, height[left]])
            ans = max(area, maxv)

            if left >= right
                right++
            else
                left++
        return ans