#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size(), 1);

        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < v.size(); j++) {
                if (i != j)
                    v[j] *= nums[i];
            }
        }
        return v;
    }
};

int main() {
	vector<int> v = {1, 2, 3, 4};

	Solution sl;

	sl.productExceptSelf(v);
}
