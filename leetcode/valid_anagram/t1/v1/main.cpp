class Solution {
public:
    bool isAnagram(string s, string t) {

        std::unordered_map<char, int>  simil;

        if (s.size() != t.size())
            return false;
        for(size_t i = 0; i < s.size(); i++) {
            simil[s[i]]++;
            simil[t[i]]--;
        }
        for (auto it3: simil) {
            if (it3.second)
                return false;
        }
    return true;
    }
};
