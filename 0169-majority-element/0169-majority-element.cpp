class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int maxElement = nums[0];
        int count = 1;

        for (int i = 1; i < len; i++) {
            if (maxElement == nums[i]) count += 1;
            else {
                count -= 1;
                if (count == 0) {
                    maxElement = nums[i];
                    count = 1;
                }
            }
        }

        return maxElement;
    }
};