#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		vector<float>	coeficent(dist.size());
		int j = 1;

		for (size_t i = 0; i < dist.size(); i++)
			coeficent[i] = static_cast<float>(dist[i]) / static_cast<float>(speed[i]);
		sort(coeficent.begin(), coeficent.end());

		for (; j < coeficent.size(); j++) {
			if ((coeficent[j - 1] - j) <= 0.0f and (coeficent[j] - j) <= 0.0f)
				return j;
		}
		return j;
    }
};

int main() {
	Solution sl;

	vector<int> v1 = {3,5,7,4,5};
	vector<int> v2 = {2,3,6,3,2};
	vector<int> v3 = {1, 1, 2, 3};
	vector<int> v4 = {1, 1, 1, 1};

	cout << "Result: " << sl.eliminateMaximum(v1, v2);
	cout << "Result: " << sl.eliminateMaximum(v3, v4);

	return 0;
}

