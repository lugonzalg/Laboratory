//Time error, memory error. The official solution.

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        size_t sz = pref.size() - 1;
        for (size_t i = sz; i > 0; i--)
            pref[i] = pref[i] ^ pref[i -1];
        return pref;
    }
};
