class Solution:
    def trap(self, height: List[int]) -> int:
        leftHeights = [0] * len(height)
        rightHeights = [0] * len(height)
        leftHeights[0] = 0
        rightHeights[len(height) - 1] = 0
        for i in range(1, len(height)):
            leftHeights[i] = max(leftHeights[i - 1], height[i - 1]) 
            rightHeights[len(height) - i - 1] = max(rightHeights[len(height) - i], height[len(height) - i])
        totalWater = 0
        for i in range(len(height)):
            currWater = min(leftHeights[i], rightHeights[i]) - height[i]
            if currWater > 0: totalWater += currWater
        
        return totalWater
