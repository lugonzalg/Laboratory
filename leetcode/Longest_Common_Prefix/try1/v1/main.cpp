#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using std::string;
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;
using std::max;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        uint16_t maxv[255] = {0};
        uint16_t uom[255][255] = {0};
        uint16_t cutter, prefix = 0;

        if (strs.size() == 1)
            return strs.at(0);

        for (auto& word: strs) {
            for (size_t i = 0; i < word.size(); i++) {
                uom[i][word[i]]++;
                maxv[i] = max(maxv[i], uom[i][word[i]]);
            }
        }

        cutter = strs.size();
        if (cutter <= 1)
            return "";
        for (size_t i = 0; i < 100; i++) {

            if (cutter > maxv[i])
                break ;            

            prefix++;
            cout << maxv[i] << " ";
        }
        return strs.at(0).substr(0, prefix);
    }
};

int main() {
    
    Solution sol;
    std::vector<std::string> words = {
        "Precaution",
        "Predict",
        "Prefix",
        "Preliminary",
        "Precede",
        "Prehistoric",
        "Predecessor",
        "Preschool",
        "Prescription",
        "Preemptive"
    };

    cout << sol.longestCommonPrefix(words);

    return 0;
}