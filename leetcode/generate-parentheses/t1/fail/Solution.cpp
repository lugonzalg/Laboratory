//!->https://www.youtube.com/watch?v=s9fokUqJ76A

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string>	res;
	string			str;

	void	generator(int open, int close, int n) {
		if (open == close and open == n) {
			res.push_back(str);
			return ;
		}

		if (open < n) {
			str.append("(");
			generator(open + 1, close, n);
			str.pop_back();
		}

		if (close < open) {
			str.append(")");
			generator(open, close + 1, n);
			str.pop_back();
		}
	}

    vector<string> generateParenthesis(int n) {
		generator(0,0, n);
		return res;
    }
};

int main() {
	Solution sl;

	vector<string> res = sl.generateParenthesis(3);
	for (auto elem: res)
		cout << elem << endl;
}
