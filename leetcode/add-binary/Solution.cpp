#include<algorithm>
#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

//https://leetcode.com/problems/add-binary/solutions/3183205/1ms-beats-100-full-explanation-append-reverse-c-java-python3/

class Solution {
public:
    string addBinary(string a, string b) {

        string res;
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0)
                carry += a[i--] - '0';

            if (j >= 0)
                carry += b[j--] - '0';

            res += carry % 2 + '0';
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {

    Solution sl;
    string a = "11", b = "1";

    cout << sl.addBinary(a, b) << endl;
    a = "1010", b = "1011";
    cout << sl.addBinary(a, b) << endl;

    return 0;
}