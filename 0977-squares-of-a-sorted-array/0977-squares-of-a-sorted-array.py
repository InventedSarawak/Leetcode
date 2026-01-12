class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        if nums[0] >= 0:
            return [num ** 2 for num in nums]
        length = len(nums)
        if nums[length - 1] < 0:
            return [num ** 2 for num in nums[::-1]]

        idx = 0
        while nums[idx] < 0 and idx < length:
            idx += 1

        neg = idx - 1
        pos = idx
        out = []
        while neg >= 0 or pos < length:
            if neg >= 0 and pos < length:
                if nums[neg] ** 2 <= nums[pos] ** 2:
                    out.append(nums[neg] ** 2)
                    neg -= 1
                else:
                    out.append(nums[pos] ** 2)
                    pos += 1
                continue
            
            while neg >= 0:
                out.append(nums[neg] ** 2)
                neg -= 1
            while pos < length:
                out.append(nums[pos] ** 2)
                pos += 1
        return out
