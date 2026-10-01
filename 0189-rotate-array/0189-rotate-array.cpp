class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size(); 
        const auto begin = nums.begin(), end = nums.end();
        const auto tillK = nums.begin() + k % len;

        reverse(begin, end);
        reverse(begin, tillK);
        reverse(tillK, end);
    }
};