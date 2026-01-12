class Solution:
    def largestGoodInteger(self, num: str) -> str:
        max_num = -1
        for i in range(len(num) - 2):
            if num[i] == num[i + 1] and num[i + 1] == num[i + 2]:
                curr = int(num[i])
                if curr > max_num:
                    max_num = curr
        if max_num == -1:
            return '' 
        return str(max_num) * 3
