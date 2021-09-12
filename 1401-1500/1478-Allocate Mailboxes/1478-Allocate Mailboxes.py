from functools import lru_cache
import math
class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        n = len(houses)
        houses.sort()
        dist = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(i + 1, n):
                median = houses[(i + j) // 2]
                for p in range(i, j + 1):
                    dist[i][j] += abs(houses[p] - median)
        @lru_cache(None)
        def dfs(i, k):
            if i == n and k == 0:
                return 0
            if i == n or k == 0:
                return math.inf
            
            result = math.inf
            for j in range(i, n):
                result = min(result, dist[i][j] + dfs(j + 1, k - 1))
            return result
        return dfs(0, k)
