class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = {}
        for idx in range(len(nums)):
            if nums[idx] in seen and abs(seen[nums[idx]] - idx) <= k:
                return True
            seen[nums[idx]] = idx
        return False