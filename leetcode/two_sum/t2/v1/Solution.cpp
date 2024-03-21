class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol(2, -1);

        unordered_map<int,int>  uom;
        unordered_map<int,int>::iterator it;
        size_t n = nums.size();

        for (size_t i = 0; i < n; i++) {
            it = uom.find(nums[i]);
            if (it != uom.end()) {
                 sol[0] = it->second;
                 sol[1] = i;
                 return sol;
            }
            uom[target - nums[i]] = i;
        }
        return sol;
    }
};
