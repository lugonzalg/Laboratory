class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        uint16_t n = nums.size();

        sort(nums.begin(), nums.end());
        for (uint16_t i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> uom;
        unordered_map<int, int>::iterator it;
        uint16_t n = nums.size();

        for (auto elem: nums) {
            it = uom.find(elem);
            if (it != uom.end())
                return true;
            uom[elem] = 1;
        }
        return false;
    }
};
