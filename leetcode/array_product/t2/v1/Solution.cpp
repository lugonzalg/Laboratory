class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> l(n), r(n);

        l[0] = 1;
        r[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] * nums[i - 1];
            r[n - i - 1] = r[n - i] * nums[n - i];
        }
        for (size_t i = 0; i < n; i++)
            nums[i] = l[i] * r[i];
        return nums;
    }
};
