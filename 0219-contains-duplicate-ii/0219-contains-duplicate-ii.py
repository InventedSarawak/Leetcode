class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = set()
        length = len(nums)
        
        for idx in range(length):
            if nums[idx] in seen:
                return True
            
            seen.add(nums[idx])
            
            if len(seen) > k:
                seen.remove(nums[idx - k])
            
        return False