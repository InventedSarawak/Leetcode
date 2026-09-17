class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique = unordered_set(nums.begin(), nums.end());
        int maxSeq = 0, currSeq = 0, currNum = 0;
        for (int num: unique) {
            if (unique.find(num - 1) == unique.end()) {
                currNum = num;
                currSeq = 1;

                while (unique.find(currNum + 1) != unique.end()) {
                    currNum += 1;
                    currSeq += 1;
                } 

                maxSeq = max(maxSeq, currSeq);
            }
        }
        return maxSeq;
    }
};