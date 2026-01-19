class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        maxPile = max(piles)
        minPile = 1
        minRate = maxPile

        while minPile <= maxPile:
            curr = (minPile + maxPile) // 2
            if not self.isValidRate(piles, h, curr): 
                minPile = minRate = curr + 1
                continue
            minRate = curr
            maxPile = curr - 1
        return minRate
        
    def isValidRate(self, piles: List[int], h: int, k: int) -> bool:
        hours = 0
        for pile in piles:
            hours += math.ceil(pile / k)
            if hours > h: return False
        return True
