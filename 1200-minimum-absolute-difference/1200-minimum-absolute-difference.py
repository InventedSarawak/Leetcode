class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        length = len(arr)
        minDiff = float('inf')
        out = []
        for idx in range(length - 1):
            if abs(arr[idx + 1] - arr[idx]) == minDiff:
                out.append([arr[idx], arr[idx + 1]])

            elif abs(arr[idx + 1] - arr[idx]) < minDiff:
                out = [[arr[idx], arr[idx + 1]]]
                minDiff = abs(arr[idx + 1] - arr[idx])

        return out