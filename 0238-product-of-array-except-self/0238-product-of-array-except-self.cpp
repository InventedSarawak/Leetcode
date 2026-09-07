class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> products(len, 1);

        int prefix = 1;
        for (int i = 0; i < len; i ++) {
            products[i] *= prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = len - 1; i > -1; i --) {
            products[i] *= suffix;
            suffix *= nums[i];
        }

        return products;
    }
};