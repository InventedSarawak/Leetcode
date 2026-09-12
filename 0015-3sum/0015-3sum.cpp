class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            int target = -nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = len - 1;

            while (l < r) {

                if (nums[l] + nums[r] < target) l++;
                else if (nums[l] + nums[r] > target) r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l ++;                 
                    while (l < r && nums[l] == nums[l - 1]) {
                        l ++;
                        continue;
                    }
                }
                    
            }
        }

        return res;
    }
};