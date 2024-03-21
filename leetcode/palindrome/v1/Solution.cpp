#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        size_t i = 0;
        stringstream        ss;

        for (auto c: s) {
            if (isalpha(c))
                ss << static_cast<char>(tolower(c));
        }

        s = ss.str();
        if (s.size() == 0)
            return false;
        size_t j = s.size() - 1;
        for (; i < j;) {
            std::cout << s[i] << std::endl;
            std::cout << s[j] << std::endl;
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};

int main() {

	Solution sl;

	sl.isPalindrome("A man, a plan, a canal: Panama");
	sl.isPalindrome(" ");
	sl.isPalindrome("aa");
}
