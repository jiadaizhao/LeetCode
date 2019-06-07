from functools import lru_cache
import math
class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        @lru_cache(None)
        def dfs(start, end):
            if end - start < 2:
                return 0
            minScore = math.inf
            for i in range(start + 1, end):
                minScore = min(minScore, A[start] * A[i] * A[end] + dfs(start, i) + dfs(i, end))
            
            return minScore

        return dfs(0, len(A) - 1)
