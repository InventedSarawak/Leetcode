class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        visited = set()
        slow = fast = max_len = 0
        while fast < len(s):
            if s[fast] not in visited:
                visited.add(s[fast])
                max_len = max(max_len, fast - slow + 1)
                fast += 1
            else:
                visited.remove(s[slow])
                slow += 1
        return max_len
