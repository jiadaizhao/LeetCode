class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        result = 0
        for i in range(len(piles) // 3, len(piles), 2):
            result += piles[i]
        return result
