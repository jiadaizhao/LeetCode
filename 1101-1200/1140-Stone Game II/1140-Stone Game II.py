from functools import lru_cache
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        presum = [0] * (len(piles) + 1)
        for i in range(len(piles)):
            presum[i + 1] = presum[i] + piles[i]

        @lru_cache(None)
        def dfs(start, M):
            if start + 2 * M >= len(piles):
                return presum[-1] - presum[start]

            maxNum = 0
            for X in range(1, M*2 + 1):
                next = dfs(start + X, max(X, M))
                maxNum = max(maxNum, presum[-1] - presum[start] - next)
            return maxNum

        return dfs(0, 1)
