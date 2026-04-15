class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        totalWater = 0
        leftMax = [0]
        rightMax = [0]

        for idx in range(length):
            leftMax.append(max(leftMax[idx], height[idx]))
            rightMax.append(max(rightMax[idx], height[length - idx - 1]))
        
        for idx in range(length):
            totalWater += min(leftMax[idx + 1], rightMax[length - idx]) - height[idx]
        
        return totalWater
        
