class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        for (size_t i = 0; i < nums.size() - 2; i++) {

            unordered_map<int, int> uom;

            for (size_t j = i; j < nums.size(); j++) {
                auto query = uom.find(nums[j]);
                if (query != uom.end() and nums[i] + nums[query->first] + nums[j] == 0) {
                    res.push_back({nums[i], nums[query->second], nums[j]});
                    uom.erase(query);
                } else if (nums[j] + (nums[i]) < 0){
                uom[-(nums[j] + (nums[i]))] = j;
                } else {
                uom[nums[j] + (nums[i])] = j;
                }
            }
        }

        return res;

    }
}
