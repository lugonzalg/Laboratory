class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> uom;
        string holder;

        for (auto word: strs) {
            holder = word;

            sort(word.begin(), word.end());
            uom[word].push_back(holder);
        }

        for (auto elem: uom)
            res.push_back(elem.second);
        return res;
    }
};
