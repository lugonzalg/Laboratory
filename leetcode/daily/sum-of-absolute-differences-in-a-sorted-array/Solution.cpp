#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*TRY 1

	Time limit exceded, it is clear that a nested loop isn't the end, but it is
	the start for me.

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		size_t n = nums.size();
		int abs_diff;
		vector<int> res;

		for (size_t i = 0; i < n; i++) {

			abs_diff = 0;
			for (size_t j = 0; j < n; j++) {
				abs_diff += abs(nums[i] - nums[j]);
			}

			res.push_back(abs_diff);
		}
		return res;
    }
};

*/

/*
 TRY 2

 if it is nested, shouldn't be just easier to calculate first the abs difference
 for the first element and the apply the difference to the rest?

 So let's say that I have 2, 3, 5 Okay, the result for this is 4,3,5.
 So let's ilustrate how it does work.

 res[0] = |2-2| + |2-3| + |2-5| = 4
 res[1] = |3-2| + |3-3| + |3-5| = 3
 res[2] = |5-2| + |5-3| + |5-5| = 5

 hmmmm

 Let's omit the difference betwen the same number, 2-2, 3-3, 5-5

 res[0] = |2-3| + |2-5| = 4
 res[1] = |3-2| + |3-5| = 3
 res[2] = |5-2| + |5-3| = 5

 it is the same... What if I sum all the values I do have to compare with?

 total[0] = 2 + 3 + 5 = 10

 For all the number it is the same result, where the difference is the number
 that it is comparing with them. For 2, it is 2 * 3 = 6

 total[0] = 2 + 3 + 5 - 6 = 4
 total[0] = 2 + 3 + 5 - 9 = 1
 total[0] = 2 + 3 + 5 - 15 = -5

 Ended up finding the solution, i was light years away haha fck.



 */

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		size_t size = nums.size();
		int left = 0, right = 0, n;
		vector<int> res;

		for (auto elem: nums)
			right += elem;

		for (size_t i = 0; i < size; i++) {
			n = nums[i];
			right -= n;

			res.push_back(n * i - left + right - n * (size - i - 1));
			left += n;
		}
		return res;
    }
};


int main() {
	Solution sl;
	vector<int> v = {2,3,5};
	vector<int> res;

	res = sl.getSumAbsoluteDifferences(v);

	cout << "Result: " << endl;
	for (auto elem: res) {
		cout << elem << endl;
	}

	return 0;
}

