class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int maxArea = 0;
        int l = 0; 
        int r = len - 1;
        
        while (l < r) {
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        
        return maxArea;
    }
};