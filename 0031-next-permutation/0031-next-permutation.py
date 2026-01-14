class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        if self.checkLargestPermutation(nums, length): 
            nums.sort()
            return

        idx = length - 1
        while idx > 0 and nums[idx - 1] >= nums[idx]:
            idx -= 1
        idx -= 1

        to_swap = self.findNextBiggestElement(nums, length, idx)
        temp = nums[to_swap]
        nums[to_swap] = nums[idx]
        nums[idx] = temp
        self.reverseTail(nums, idx + 1)

    def checkLargestPermutation(self, nums: List[int], length: int) -> bool:
        for idx in range(length):
            if idx == length - 1: return True
            if nums[idx] < nums[idx + 1]: return False

    def findNextBiggestElement(self, nums: List[int], length: int, idx: int) -> int:
        begin = idx
        val = nums[idx]
        large = float('inf')
        idx_large = 0
        for idx in range(length - 1, begin, -1):
            if nums[idx] > val and nums[idx] < large:
                large = nums[idx]
                idx_large = idx
        return idx_large      

    def reverseTail(self, nums: List[int], idx: int) -> None:
        left = idx
        right = len(nums) - 1

        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1