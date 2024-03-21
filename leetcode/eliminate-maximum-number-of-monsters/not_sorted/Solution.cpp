#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		size_t i = 0, j = 0;
		int	finish;
		int	moves = 0;

		while (true) {
			finish = 0;
			i = j;
			moves++;

			for (; i < dist.size(); i++) {
				dist[i] -= speed[i];
				if (dist[i] == 0){
					finish++;
					if (finish > 1)
						return moves;
				}

			}
			j++;
			if (j == dist.size())
				return moves;
		}
    }
};

int main() {
	Solution sl;

	vector<int> v1 = {1, 3, 4};
	vector<int> v2 = {1, 1, 1};
	vector<int> v3 = {1, 1, 2, 3};
	vector<int> v4 = {1, 1, 1, 1};

	cout << "Result: " << sl.eliminateMaximum(v1, v2);
	cout << "Result: " << sl.eliminateMaximum(v3, v4);

	return 0;
}

