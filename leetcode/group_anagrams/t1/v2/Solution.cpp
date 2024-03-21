#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:

    int get_sum(const std::string &str) {
        int sum;

        sum = 1;
        for (char c: str)
            sum *= c;
        return sum;
    }


    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<int, std::vector<std::string>> _uom;

        for (auto it: strs) {

            std::string word = it;
            std::cout << word << std::endl;
            //sort(word.begin(), word.end());
            int sum = this->get_sum(it);
            std::cout << word << std::endl;
            _uom[sum].push_back(it);
        }

        std::vector<std::vector<std::string>> res;
        for (auto it: _uom)
            res.push_back(it.second);
        return res;
    }
};

int main() {
	Solution sl;

    std::vector<std::string> v = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> res;

    sl.groupAnagrams(v);
	return 0;
}
