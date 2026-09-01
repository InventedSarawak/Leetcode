class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;

        for (int i = 0; i < nums.size(); i ++) {
            diff[target - nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (diff.find(nums[i]) != diff.end() && i != diff[nums[i]]) {
                return {i, diff[nums[i]]};
            }
        }

        return {-1, -1};
    }
};