#include<iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int mySqrt(int x) {

        long prev_n;

        for (long n = 1; n * n <= x; n *= 2)
            prev_n = n;

        for (long n = 1; n * n <= x; n++)
            prev_n = n;
        return prev_n;
    }
};

int main() {

    Solution sl;

    cout << sl.mySqrt(25) << endl;;
    cout << sl.mySqrt(26) << endl;;
    cout << sl.mySqrt(35) << endl;;
    cout << sl.mySqrt(36) << endl;;

    return 0;
}