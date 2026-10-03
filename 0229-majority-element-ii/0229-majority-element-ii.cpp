class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        int firstMax = 0, secondMax = -1, firstFreq = 1, secondFreq = 0;
        for (int i = 1; i < len; i++) {
            if (secondMax == -1 && nums[i] != nums[firstMax]) {
                secondMax = i;
                secondFreq = 1;
                continue;
            }

            if (nums[i] == nums[firstMax]) firstFreq++;
            else if (nums[i] == nums[secondMax]) secondFreq++;

            else if (firstFreq == 0) {
                firstMax = i;
                firstFreq = 1;
            }

            else if (secondFreq == 0) {
                secondMax = i;
                secondFreq = 1;
            }

            else {
                firstFreq--;
                secondFreq--;
            }
        }

        if (secondMax == -1 && firstMax == -1) return {};

        if (secondMax == -1 || firstMax == -1) {
            int curr = secondMax == -1 ? firstMax : secondMax;
            int freq = 0;
            for (int num: nums) {
                if (num == nums[curr]) freq++;
            }
            if (freq > len / 3) return {nums[curr]};
            else return {};
        }

        vector<int> freqs(2);
        for (int num: nums) {
            if (num == nums[firstMax]) freqs[0]++;
            if (num == nums[secondMax]) freqs[1]++;
        }

        vector<int> res;
        if (freqs[0] > len / 3) res.push_back(nums[firstMax]);
        if (freqs[1] > len / 3) res.push_back(nums[secondMax]);

        return res;
    }
};