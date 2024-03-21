#include <iostream>
#include <vector>
#include <string>

class Solution {
public:

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>>  v = {{}};

        v[0].push_back(strs.front());
        for (size_t i = 1; i < strs.size(); i++) {
            int check[26] = {0};
            std::cout << strs[i] << std::endl;
            bool pushed = true;
            for (auto vit: v) {
                for (size_t j = 0; j < vit[0].size(); j++) {
                    check[vit[0][j]]++;
                    check[strs[i][j]]++;
                }
                size_t k;
                for (k = 0; k < 26; k++) {
                    if (check[k])
                        break ;
                }
                if (k == 26) {}
                    pushed = false;
                    vit.push_back(strs[i]);
                }
            }
        }
        return v;
    }
};

int main() {
    Solution sl;
    std::vector<std::string> v = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> res;

    sl.groupAnagrams(v);
}
