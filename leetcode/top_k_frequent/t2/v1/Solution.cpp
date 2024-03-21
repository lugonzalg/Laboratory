bool my_sort(pair<int,int> a, pair<int, int> b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int16_t, uint16_t>   m;
        vector<pair<int16_t,uint16_t>> holder;
        vector<int> res;

        for (auto elem: nums)
            m[elem]++;

        for (auto elem: m)
            holder.push_back(elem);

        sort(holder.begin(), holder.end(), my_sort);
        for (size_t i = 0; i < k; i++)
            res.push_back(holder[i].first);
        return res;
    }
};
