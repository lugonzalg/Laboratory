#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int> > ans;

       ans.push_back({1});
       if (numRows == 1)
        return ans;

       ans.push_back({1, 1});
       if (numRows == 2)
        return ans;

        for (size_t i = 2; i < numRows; i++) {
            vector<int> v(i + 1, 1);
            
            ans.push_back(v);
            for (size_t j = 1; j < i; j++) {

               ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]; 

            }
        }

        return ans;
    }
};

int main() {

    Solution sl;

    for (auto& elem: sl.generate(5)) {
        for (auto& num: elem)
            cout << num;
        cout << endl;
    }

}