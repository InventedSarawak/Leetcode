class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq: dict[str, int] = {}
        for ch in s1:
            if ch not in freq:
                freq[ch] = 0
            freq[ch] += 1
        left = 0
        safe_freq = copy.deepcopy(freq)
        # print(freq)
        for right in range(len(s2)):
            if s2[right] in freq and freq[s2[right]] > 0:
                freq[s2[right]] -= 1
                # print(freq, s2[left:right+1])
                if freq[s2[right]] == 0 and all(count == 0 for count in freq.values()):
                    return True
            else:
                if s2[right] not in freq:
                    freq = copy.deepcopy(safe_freq)
                    left = right + 1
                else:
                    while freq[s2[right]] == 0:
                        freq[s2[left]] += 1
                        left += 1
                    freq[s2[right]] -= 1    
                # print(freq, s2[left:right+1])
        return False