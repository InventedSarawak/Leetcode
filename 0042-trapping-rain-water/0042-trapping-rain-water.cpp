class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> lMax(len);
        vector<int> rMax(len);
        lMax[0] = 0, rMax[len - 1] = 0;

        for (int i = 1; i < len; i ++) {
            lMax[i] = max(lMax[i - 1], height[i - 1]);
            rMax[len - i - 1] = max(rMax[len - i], height[len - i]);
        }

        int totalWater = 0;
        for (int i = 0; i < len; i ++) {
            totalWater += min(lMax[i], rMax[i]) > height[i] ? min(lMax[i], rMax[i]) - height[i] : 0;
        }

        return totalWater;
    }
};