#include<iostream>
#include<string>
#include<unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:

    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> uomS, uomT;

        if (s.size() != t.size())
            return false;

        for (size_t idx = 0; idx < s.size(); idx++) {

            auto elemS = uomS.find(s[idx]);
            auto elemT = uomT.find(t[idx]);

            if (elemS == uomS.end()) {
                uomS[s[idx]] = t[idx];
            }
            else if (elemS->second != t[idx])
                return false;

            if (elemT == uomT.end()) {
                uomT[t[idx]] = s[idx];
            }
            else if (elemT->second != s[idx])
                return false;
        }
        return true;
    }

};

int main() {

    Solution sl;

    cout << std::boolalpha << sl.isIsomorphic("babc", "baba");

    return 0;
}