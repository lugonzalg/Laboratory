//HINT -> https://leetcode.com/problems/valid-anagram/solutions/3687854/3-method-s-c-java-python-beginner-friendly/

class Solution {
public:
    bool isAnagram(string s, string t) {

        int arr[26] = {0};

        if (s.size() != t.size())
            return false;
        for(size_t i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (size_t i = 0; i < 26; i++) {
            std::cout << arr[i] << std::endl;
            if (arr[i] != 0)
                return false;
        }
    return true;
    }
};
