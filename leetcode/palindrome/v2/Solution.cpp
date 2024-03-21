#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0;
        int j = s.size() - 1;
        for (; i < j;) {
            for (; !std::isdigit(s[i]) and !std::isalpha(s[i]) and s[i]; i++);
            for (; !std::isdigit(s[j]) and !std::isalpha(s[j]) and j; j--);

            if (i > s.size() or !j)
                break ;

            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            if (isalpha(s[j]))
                s[j] = tolower(s[j]);

            std::cout << s[i] << std::endl;
            std::cout << s[j] << std::endl;

            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

	Solution sl;

    std::cout << sl.isPalindrome("A man, a plan, a canal: Panama");
    std::cout << sl.isPalindrome(" ");
    std::cout << sl.isPalindrome("aa");
    std::cout << sl.isPalindrome("a.");
    std::cout << sl.isPalindrome(".,");
}
