//Thank you :) https://www.youtube.com/watch?v=UuiTKBwPgAo

class Solution {
public:
    int maxArea(vector<int>& height) {
       int start;
       int end = height.size() - 1;
       int max = 0;
    
        for (size_t start = 0; start < end;) {
    
            if (height[start] <= height[end]) {
    
                if (max < (end - start) * height[start])
                    max = (end - start) * height[start];
                start++;

            } else if (height[start] > height[end]) {
                if (max < (end - start) * height[end])
                    max = (end - start) * height[end];
                end--;

            }
    
        }
        return max;
    }
}
