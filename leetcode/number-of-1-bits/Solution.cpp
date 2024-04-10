class Solution {
public:
    int hammingWeight(int n) {

        int count = 0;

        while (n) {

            count += 1 & n;
            n >>= 1;
        }
        return count;
        
    }
};