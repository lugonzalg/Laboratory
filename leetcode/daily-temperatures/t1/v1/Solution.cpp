#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>   s;
        vector<int>             v;
        pair<int, int>          holder;
        size_t                  n = temperatures.size() - 1;

        s.push(make_pair(n, temperatures[n]));
        for (; n > 0; n--) {
            holder = s.top();
            if (holder.second < temperatures[n]) {
                while (holder.second < temperatures[n] and s.size()) {
                    s.pop();
                    if (s.size())
                        holder = s.top();
                }
                if (!s.size())
                    v.insert(v.begin(), 0);
                else
                    v.insert(v.begin(), holder.first - n);

                s.push(make_pair(n, temperatures[n]));
            } else {
                v.insert(v.begin(), holder.first - n);
                s.push(make_pair(n, temperatures[n]));
            }
        }
        holder = s.top();
        while (holder.second < temperatures[n] and s.size()) {
            s.pop();
            if (s.size())
                holder = s.top();
        }
        if (!s.size())
            v.insert(v.begin(), 0);
        else
            v.insert(v.begin(), holder.first - n);

        return v;
    }
};

int main() {

    Solution sl;
    vector<int> v = {73,74,75,71,69,72,76,73};
    vector<int> res;

    res = sl.dailyTemperatures(v);
    for (auto elem: res) {
        cout << elem << " - ";
    }
    cout << endl;

    return 0;
}
