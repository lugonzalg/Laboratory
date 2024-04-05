#include<iostream>
#include<vector>

using std::vector;
using std::endl;
using std::cout;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> res;

        for (auto rit = digits.rbegin(); rit != digits.rend(); rit++){

            *rit += 1;

            if (*rit > 9) {
                *rit = 0;
                continue ;
            }

            break ;

        }

        if (!digits[0])
            res.push_back(1);
        for (auto& elem: digits)
            res.push_back(elem);

        return res;
    }
};

int main() {

    Solution sl;
    vector<int> v = {1,2,3};
    vector<int> v2 = {9};

    for (auto& elem: sl.plusOne(v))
        cout << elem;
    cout << endl;

    for (auto& elem: sl.plusOne(v2))
        cout << elem;
    cout << endl;

    return 0;
}