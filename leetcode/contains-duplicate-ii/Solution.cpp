#include<unordered_map>
#include<vector>
#include<iostream>

using std::unordered_map;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> uom;
        size_t n = nums.size();
        int retval;

        for (size_t i = 0; i < n; i++) {

            retval = uom[nums[i]];
            if (retval) {

                if (abs(retval - i - 1) <= k)
                    return true;

            }

            uom[nums[i]] = i + 1;
        }

        return false;
        }
};

int main() {

    Solution sl;
    vector<int> v = {1, 2, 3, 1};
    int k = 3;

    cout << std::boolalpha << sl.containsNearbyDuplicate(v, k) << endl;
    v = {1,2,3,1,2,3};
    k = 2;
    cout << std::boolalpha << sl.containsNearbyDuplicate(v, k) << endl;

    return 0;
}