class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        minDiff = float('inf')
        out = []
        for idx in range(len(arr) - 1):
            currDiff = abs(arr[idx + 1] - arr[idx])

            if currDiff == minDiff:
                out.append([arr[idx], arr[idx + 1]])

            elif currDiff < minDiff:
                out = [[arr[idx], arr[idx + 1]]]
                minDiff = currDiff

        return out