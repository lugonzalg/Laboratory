#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    vector<int> generate(int rowIndex) {
       vector<vector<int> > ans;

       ans.push_back({1});
       if (rowIndex == 0)
        return ans[0];

       ans.push_back({1, 1});
       if (rowIndex == 1)
        return ans[1];

        for (size_t i = 2; i <= rowIndex; i++) {
            vector<int> v(i + 1, 1);
            
            ans.push_back(v);
            for (size_t j = 1; j < i; j++) {

               ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]; 

            }
        }

        return ans[rowIndex];
    }
};

int main() {

    Solution sl;

    for (auto& elem: sl.generate(3)) {
        cout << elem;
    }

}