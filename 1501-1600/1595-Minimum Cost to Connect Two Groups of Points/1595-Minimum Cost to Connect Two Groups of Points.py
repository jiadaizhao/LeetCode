import math
from functools import lru_cache
class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        size1, size2 = len(cost), len(cost[0])
        minCost2 = [min(cost[i][j] for i in range(size1)) for j in range(size2)]
        @lru_cache(None)
        def dfs(start, mask):
            if start == size1:
                result = 0
                for j in range(size2):
                    if mask & (1 << j) == 0:
                        result += minCost2[j]
            else:
                result = math.inf
                for j in range(size2):
                    result = min(result, cost[start][j] + dfs(start + 1, mask | (1 << j)))
            return result
        return dfs(0, 0)
