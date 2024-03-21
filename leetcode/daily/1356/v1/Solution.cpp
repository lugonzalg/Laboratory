class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>>           uom;
        vector<int>             res;
        int count;

        for (auto elem: arr) {
            
            count = 0;
            for (size_t i = 0; i < 32; i++) {
                if (elem & (1 << i))
                    count++;
            }
            uom[count].push_back(elem);
        }
        for (auto elem: uom) {
            sort(elem.second.begin(), elem.second.end());
            for (auto item: elem.second) {
                res.push_back(item);
            }
        }
        return res;
    }
}
