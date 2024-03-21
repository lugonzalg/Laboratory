#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        size_t n = nums.size();
        size_t maxl = 0;
        vector<int> res;

        for (int y = 0; y < n; y++) {

            size_t x = 0;
            maxl = max(maxl, nums[y].size());
            for (int y2 = y; y2 > -1; y2--) {

                if (nums[y2].size() > x)
                    res.push_back(nums[y2][x]);
                x++;
            }
        }

        for (int x = 1; x < maxl; x++) {
            int y = n - 1;
            for (int x2 = x; y > -1; x2++) {
                if (x2 < nums[y].size())
                    res.push_back(nums[y][x2]);
                y--;
            }
        }
        return res;
    }
};

int main() {
	Solution sl;

	vector<vector<int>> vv = {{1,2,3},{4},{7,8,9}};
	vector<vector<int>> vv2 = {{1,2,3,4,5,6}};

	sl.findDiagonalOrder(vv2);

	return 0;
}

