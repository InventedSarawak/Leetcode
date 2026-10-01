class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int maj_ele = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == maj_ele){
                count++;
            }
            else{
                count--;
                if(count == 0){
                    maj_ele = nums[i];
                    count = 1;
                }
            }
        }
        return maj_ele;
    }
};