#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    int titleToNumber(string columnTitle) {

        int ans = 0, exp = 1;

        for (auto rit = columnTitle.rbegin(); rit != columnTitle.rend(); rit++) {
            ans += (*rit - '@') * exp;
            exp *= 26;
        }

        return ans;
        
    }
};

int main() {

    Solution sl;

    cout << sl.titleToNumber("ZY") << endl;

    return 0;

}