class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int>    result;
        std::vector<int> v = {-1, -1};

        for (size_t i = 0; i < nums.size(); i++) {
            auto it = result.find(nums[i]);
            if (it != result.end()){
                v[0] = it->second;
                v[1] = i;
                return v;
            }
            result[target - nums[i]] = i;
        }
        return v;
    }
};
