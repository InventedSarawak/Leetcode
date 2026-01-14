class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        out = set([])
        nums.sort()
        length = len(nums)
        for i in range(length - 2):

            if i > 0 and nums[i] == nums[i - 1]:
                continue

            target = -nums[i]

            right = length - 1
            left = i + 1

            while right > left:
                if nums[right] + nums[left] > target:
                    right -= 1
                elif nums[right] + nums[left] < target:
                    left += 1
                else: 
                    out.add((nums[i], nums[left], nums[right]))
                    left += 1
                    right -= 1

        return [list(t) for t in out]
