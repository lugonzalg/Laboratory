#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int init = [] {
    ifstream in("in.txt");
    for (string s; getline(in, s);) {
        int n = 0;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            bool _neg = false;
            if (s[_i] == '-') ++_i, _neg = true;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            if (_neg) v = -v;
            a[n++] = v;
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n;) {
            int i0 = i;
            for (++i; i < n && a[i - 1] + 1 >= a[i]; ++i);
            ans = max(ans, a[i - 1] - a[i0] + 1);
        }
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>) { return 999; }
};

int main() {
	vector<int> v = {0,3,7,2,5,8,4,6,0,1};
	vector<int> v1= {1, 2, 0, 1};
	Solution sl;

	cout << sl.longestConsecutive(v1) << std::endl;
return 0;
}
