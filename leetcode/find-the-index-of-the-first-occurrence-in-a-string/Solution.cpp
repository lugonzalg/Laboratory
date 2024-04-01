#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

/* TRY 1 -> cpp style
class Solution {
public:
    int strStr(string haystack, string needle) {

        int pos = haystack.find(needle);
        if (pos == -1)
            return -1;
        return pos;
    }
};*/

class Solution {
public:
    int strStr(string haystack, string needle) {

        const char *src = haystack.c_str();
        const char *key = needle.c_str();

        const char *tmp_src;
        const char *tmp_key;
        while (*src) {

            if (*src == *key) {
                tmp_src = src;
                tmp_key = key;

                while (*tmp_src and *tmp_key and *tmp_src == *tmp_key) {
                    tmp_key++;
                    tmp_src++;
                }
                if (!(*tmp_key))
                    return src - haystack.c_str();
                else
                    src++;
            }
            else
                src++;

        }

    return -1;
    }

};

int main(int argc, char *argv[]) {

    Solution sl;

    // Sample 1
    std::string haystack1 = "mississippi";
    std::string needle1 = "issip";

    // Sample 2
    std::string haystack2 = "banana";
    std::string needle2 = "ana";

    // Sample 3
    std::string haystack3 = "hello";
    std::string needle3 = "hi";

    cout << "Result[1]: " << sl.strStr(haystack1, needle1) << endl;
    cout << "Result[2]: " << sl.strStr(haystack2, needle2) << endl;
    cout << "Result[3]: " << sl.strStr(haystack3, needle3) << endl;

}
