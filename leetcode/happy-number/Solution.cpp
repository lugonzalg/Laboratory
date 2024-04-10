#include<iostream>
#include<cmath>

using std::cout;
using std::endl;
using std::pow;

//https://leetcode.com/problems/happy-number/solutions/4992320/c-done-easily-with-looping-0ms/

class Solution {
public:
    bool isHappy(int n) {

        int new_val;
        
        while (n != 1 and n != 4) {

            new_val = 0;
            while (n) {
                new_val += pow((n % 10), 2);
                n /= 10;
            }
            n = new_val;
        }
        return new_val == 1;
    }
};

int main() {

    Solution sl;

    cout << std::boolalpha << sl.isHappy(2) << endl;

    return 0;
}