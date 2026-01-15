class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        right = 1
        minLength = len(nums) + 1
        currSum = nums[0]
        while left < right and right <= len(nums):
            if currSum < target:
                if right < len(nums): 
                    currSum += nums[right]
                right += 1
                continue
            
            minLength = min(minLength, right - left)  

            if currSum > target: 
                currSum -= nums[left]
                left += 1
                continue

            if right < len(nums): 
                currSum += nums[right]
            right += 1

        if minLength == len(nums) + 1: return 0
        return minLength


                

