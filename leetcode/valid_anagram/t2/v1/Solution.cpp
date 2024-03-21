class Solution {
public:
    bool isAnagram(string s, string t) {

        uint16_t hash_map[26] = {0};
        uint16_t n = s.size();

        if (s.size() != t.size())
            return false;

        for (uint16_t i = 0; i < n; i++) {
            hash_map[s[i] - 'a']++;
            hash_map[t[i] - 'a']--;
        }
        for (uint16_t i = 0; i < 26; i++) {
            if (hash_map[i])
                return false;
        }
        return true;
    }
};
