class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        length = len(arr)
        minDiff = abs(arr[1] - arr[0])
        out = []
        for idx in range(length - 1):
            minDiff = min(minDiff, abs(arr[idx + 1] - arr[idx]))
        for idx in range(length - 1):
            if abs(arr[idx + 1] - arr[idx]) == minDiff:
                out.append([arr[idx], arr[idx + 1]])
        return out