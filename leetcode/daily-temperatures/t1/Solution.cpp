class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t n = temperatures.size(), j;
        vector<int> res;
        unsigned count;
        for (size_t i = 0; i < n; i++) {
            count = 1;
            for (j = i + 1; j < n; j++) {
                if (temperatures[i] < temperatures[j]) {
                    res.push_back(count);
                    break ;
                }
                count++;
            }
            if (j == n)
                res.push_back(0);
        }
        return res;
    }
};
