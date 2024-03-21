class Solution {
public:

    static bool    _sort_map(pair<int, int> start, pair<int, int> end) {
        return start.second > end.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        std::vector<std::pair<int, int>> vp;
        vector<int> v;

        //sort(nums.begin(), nums.end());
        for (auto num: nums) {
            m[num]++;
        }

        for (auto it: m) {
            vp.push_back(it);
        }

        std::sort(vp.begin(), vp.end(), _sort_map);

        for (auto it: vp) {
            if (!k--)
                break ;
            v.push_back(it.first);

        }
        return v;
    }
};
