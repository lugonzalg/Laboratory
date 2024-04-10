#include<iostream>
#include<vector>
#include<unordered_map>

using std::unordered_map;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> uom;
        size_t n = nums.size() / 2;

        for (auto &num: nums) {

            uom[num]++;
            if (uom[num] == n)
                return num;
        }
        return -1;
    }
};

int main() {

    Solution sl;
    vector<int> v = {1,2,3,1,1,2};

    cout << "Response: " << sl.majorityElement(v) << endl;

    return 0;
}