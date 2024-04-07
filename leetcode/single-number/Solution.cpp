#include<vector>
#include<unordered_map>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;
using std::unordered_map;

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> uom;
        int unique;

        for (auto& num: nums)
            uom[num]++;

        for (auto& [key, val]: uom)
            if (val == 1)
                return key;
        return -1;
    }
};
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (auto& num: nums)
            ans ^= num;
        return ans;
    }
};

int main() {

    Solution sl;
    vector<int> v = {1,2,3,1,2};

    cout << "Res: " << sl.singleNumber(v) << endl;
}