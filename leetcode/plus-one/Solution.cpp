#include<iostream>
#include<vector>

using std::vector;
using std::endl;
using std::cout;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for (auto rit = digits.rbegin(); rit != digits.rend(); rit++){

            *rit = (*rit + 1) % 10;

            if (*rit != 0)
                break ;
        }

        if (!digits[0])
            digits.insert(digits.begin(), 1);

        return digits;
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