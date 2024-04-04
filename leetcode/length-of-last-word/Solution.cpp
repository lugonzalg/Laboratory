#include<string>
#include<iostream>
#include <ctype.h>

using std::string;
using std::endl;
using std::cout;

class Solution {
public:
    int lengthOfLastWord(string s) {

        size_t n = s.size();
        size_t start, end = n;

        for (; end and !isalpha(s[end]); end--);

        for (start = end; start and s[start] != ' '; start--);

        if (s[start] != ' ') end++;
        return end - start;
    }
};

int main() {

    Solution sl;

    cout << "Length: " << sl.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    cout << "Length: " << sl.lengthOfLastWord("   moon  ") << endl;
    cout << "Length: " << sl.lengthOfLastWord("moon  ") << endl;
    cout << "Length: " << sl.lengthOfLastWord(" moon") << endl;

    return 0;    
}