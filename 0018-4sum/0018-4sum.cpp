class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < len - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long long sum = (long long) target - nums[i] - nums[j];
                int left = j + 1, right = len - 1;

                while (left < right) {
                    if (nums[left] + nums[right] < sum) left++;
                    else if (nums[left] + nums[right] > sum) right--;
                    else {
                        if (left > j + 1 && nums[left] == nums[left - 1]) {
                            left++;
                            continue;
                        }
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                    }
                }
            } 

        }

        return result;
    }
};