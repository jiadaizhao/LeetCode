from functools import lru_cache
import math
class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        @lru_cache(None)
        def dfs(i, pc, t):
            if i == m:
                return 0 if t == 0 else math.inf
            if t < 0 or m - i < t:
                return math.inf
            if houses[i] == 0:
                return min(dfs(i + 1, c, t - (pc != c)) + cost[i][c - 1] for c in range(1, n + 1))
            else:
                return dfs(i + 1, houses[i], t - (pc != houses[i]))
        
        result = dfs(0, -1, target)
        return result if result != math.inf else -1
