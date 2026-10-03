class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        int firstIdx = 0, secondIdx = -1, firstVotes = 1, secondVotes = 0;
        for (int i = 1; i < len; i++) {
            if (secondIdx == -1 && nums[i] != nums[firstIdx]) {
                secondIdx = i;
                secondVotes = 1;
                continue;
            }

            if (nums[i] == nums[firstIdx]) firstVotes++;
            else if (nums[i] == nums[secondIdx]) secondVotes++;
            else if (firstVotes == 0) firstIdx = i, firstVotes = 1;
            else if (secondVotes == 0) secondIdx = i, secondVotes = 1;
            else firstVotes--, secondVotes--;
        }

        int firstCount = 0, secondCount = 0;
        for (int num : nums) {
            if (num == nums[firstIdx]) firstCount++;
            if (secondIdx != -1 && num == nums[secondIdx]) secondCount++;
        }

        vector<int> res;
        if (firstCount > len / 3) res.push_back(nums[firstIdx]);
        if (secondCount > len / 3) res.push_back(nums[secondIdx]);
        return res;
    }
};