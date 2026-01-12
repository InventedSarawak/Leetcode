class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        length = len(arr)
        if length < 3: return 0
        largest_mountain = 0
        idx = 1

        while idx < length - 1:
            left = right = 0
            if arr[idx - 1] >= arr[idx]:
                idx += 1
                continue
            while idx < length and arr[idx - 1] < arr[idx]:
                left += 1
                idx += 1
            while idx < length and arr[idx - 1] > arr[idx]:
                right += 1
                idx += 1
            
            if right == 0:
                continue
            
            curr = left + right + 1

            largest_mountain = max(largest_mountain, curr)
            idx -= 1
        return largest_mountain