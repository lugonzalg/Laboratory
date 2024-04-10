#include<algorithm>
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int aux;

        while (columnNumber){

            aux = columnNumber % 26;

            if (aux) {
                ans += '@' + aux;
                columnNumber -= aux;
            } else {
                aux = columnNumber / 26;
                ans += '@' + aux;
                columnNumber = aux;
                if (columnNumber <= 26)
                    break ;
            }

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    Solution sl;

    sl.convertToTitle(701);

    return 0;
}