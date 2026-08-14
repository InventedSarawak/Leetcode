from collections import Counter

class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        n = len(s)
        c = Counter()
        l = 0
        r = 0
        res = 0
        while r < n:
            c[s[r]] += 1

            while c[s[r]] > 2:
                c[s[l]] -= 1
                l += 1

            res = max(res, r-l+1)
            r += 1
        return res

