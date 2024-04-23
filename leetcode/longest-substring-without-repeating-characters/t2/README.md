3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
Companies
Hint

Given a string s, find the length of the longest
substring
without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.

Analysis:

    step 1:
        I have to retrieve the length of the largest substring. I will use a hash_set for storing values.

        when a character is found I will start from 0, repeat until string ended and return the maximun length measured.

    step 2:
        hehe. Just using a hash_set does not work.

            i.e
                dvdf

        When the d value is found twice and the hash_set restarts, v is lost, so I have to use two pointers to restart from the counting

Algorithm:

    step 1:
        init hash_set
        iterate over all

            letter in hash_set:
                ans = max count, ans
                count = 1
                hash_set clear
            else
                count += 1

            add letter

    step 2:

        left, right, n = 0, 0, len(s)
        init set

        while right < n

            if s[right] in set:

                ans = max right - left, ans
                left += 1
                right = left
                set reset
            else
                count += 1

            set.add.letter
        return max(ans, right - left)