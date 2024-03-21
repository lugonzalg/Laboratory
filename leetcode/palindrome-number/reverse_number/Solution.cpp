#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        uint16_t r = 0, h = x;

        if (x < 0)
            return false;

        while (x) {
            r = (r * 10) + (x % 10);
            x /= 10;
        }
        return r == h;
    }
};

int main() {
	Solution sl;

	sl.

	return 0;
}

