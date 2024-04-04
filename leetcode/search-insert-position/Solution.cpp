
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

/*Try 1 linear seatch O(n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        size_t n = nums.size();

        for (size_t idx = 0; idx < n; idx++) {

            if (nums[idx] == target or nums[idx] > target)
                return idx;
        }
        return -1;
    }
};*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        size_t n = nums.size();
        size_t low = 0, high = n - 1, mid;

        if (target > nums[high])
            return n;
        else if (target < nums[low])
            return 0;

        while (low <= high) {

            mid = (low + high) / 2;

            if (target == nums[mid])
                return mid;

            if (target > nums[mid])
                 low = mid + 1;
            else
                high = mid - 1;
        }

        return low;

    }
};

int main(int argc, char *argv[]) {

   vector<int> v1 = {1,3,5,6}; 
   vector<int> v2 = {1,3};

   Solution sl;

   cout << sl.searchInsert(v1, 2) << endl;
   cout << sl.searchInsert(v1, 4) << endl;
   cout << sl.searchInsert(v1, 7) << endl;

   cout << sl.searchInsert(v2, 2) << endl;

}
