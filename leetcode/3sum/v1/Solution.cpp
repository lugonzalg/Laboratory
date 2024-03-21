//Thank you :) https://www.youtube.com/watch?v=jzZsG8n2R9A

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 2; i++) {
            int start;
            int end;

            start = i + 1;
            end = nums.size() - 1;
            if (i and nums[i] == nums[i - 1]) continue;
            while (start < end) {
                if (nums[i] + nums[start] + nums[end] == 0) {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    while(nums[start] == nums[start - 1] and start < end)
                        start++;
                }
                else if (nums[i] + nums[start] + nums[end] < 0) start++;
                else end--;
            }
        }
        return res;

    }
}
