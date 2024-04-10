#include<iostream>

using std::cout;
using std::endl;

/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t ans = 0;

        for (size_t idx = 0; idx < 32; idx++) {

            cout << (1 << (31 - idx)) << endl;
            cout << idx << endl;
            cout << ((1 << (31 - idx)) & n) << endl;
            cout << endl;
            ans |= ((1 << (31 - idx)) & n) << idx;
        }
        return ans;
        
    }
};
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t ans = 0;

        for (size_t idx = 0; idx < 32; idx++) {

            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;

        }
        return ans;
        
    }
};

int main() {

    Solution sl;

    cout << sl.reverseBits(3) << endl;

    return 0;

}