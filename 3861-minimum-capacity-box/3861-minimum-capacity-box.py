class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        minimumViableCapacity: float = float("inf")
        out = 0
        for idx, cap in enumerate(capacity):
            if cap < itemSize:
                continue
            if cap < minimumViableCapacity:
                minimumViableCapacity = cap
                out = idx
        return out if minimumViableCapacity != float('inf') else -1