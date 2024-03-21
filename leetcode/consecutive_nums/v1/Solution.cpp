#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int sum = 1;
        int max = 0;
        int past = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] - past == 1)
                sum++;
            else if (nums[i] - past != 0){
                if (max < sum)
                    max = sum;
                sum = 1;
            }
            past = nums[i];
        }
        if (sum > max)
            return sum;
        return max;
    }
};

int main() {
	vector<int> v = {0,3,7,2,5,8,4,6,0,1};
	vector<int> v1= {1, 2, 0, 1};
	Solution sl;

	cout << sl.longestConsecutive(v1) << std::endl;
return 0;
}
