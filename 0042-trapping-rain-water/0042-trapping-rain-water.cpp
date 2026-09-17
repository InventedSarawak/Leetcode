class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (l <= r) {
            if (height[l] < height[r]) {
                leftMax = max(leftMax, height[l]);
                totalWater += leftMax - height[l];
                l ++;
            } else {
                rightMax = max(rightMax, height[r]);
                totalWater += rightMax - height[r];
                r --;
            }
        }
        return totalWater;
    }
};