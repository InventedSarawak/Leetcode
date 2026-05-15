class Solution:
    def minWindow(self, s: str, t: str) -> str:
        char = Counter(t)
        minWindowSubstringLength = len(s)
        totalDigitsLeft = len(char)
        minWindowSubstring = ""
        bestLeft = bestRight = -1

        left = 0
        for right in range(len(s)):
            # if s[right] not in char:
            #     continue
            
            if char[s[right]] == 1:
                totalDigitsLeft -= 1
            char[s[right]] -= 1

            while left <= right and totalDigitsLeft == 0:
                if minWindowSubstringLength >= right - left + 1:
                    bestLeft = left
                    bestRight = right
                    minWindowSubstringLength = right - left + 1

                if s[left] in char:
                    if char[s[left]] == 0:
                        totalDigitsLeft += 1
                    char[s[left]] += 1
                left += 1

        return s[bestLeft: bestRight + 1] if bestRight != -1 else  ""

