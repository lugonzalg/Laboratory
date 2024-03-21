#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string num;

        num = to_string(x);
        size_t end = num.size() - 1;

        for (size_t i = 0; i < num.size() / 2; i++) {
            if (num[i] != num[end - i])
                return false;
        }
        return true;
    }
};

int main() {
	Solution sl;

	sl.

	return 0;
}

