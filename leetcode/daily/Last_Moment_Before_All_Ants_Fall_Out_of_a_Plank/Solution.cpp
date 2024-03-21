#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		int moves = 0;

		for (auto elem: left)
			moves = max(abs(elem - 0), moves);

		for (auto elem: right)
			moves = max(abs(elem - n), moves);

		return moves;
    }
};

int main() {

	Solution sl;
	vector<int> v1 = {4,3};
	vector<int> v2 = {0,1};

	sl.getLastMoment(4, v1, v2);

	return 0;
}
