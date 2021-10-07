from functools import lru_cache
import math
class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(None)
        def dfs(curr, k, prev, prevCount):
            if len(s) - curr < k or k < 0:
                return math.inf
            if curr == len(s):
                return 0    
            if s[curr] == prev:
                incr = 1 if (prevCount == 1 or prevCount == 9 or prevCount == 99) else 0
                return incr + dfs(curr + 1, k, prev, prevCount + 1)
            else:
                keepCount = 1 + dfs(curr + 1, k, s[curr], 1)
                deleteCount = dfs(curr + 1, k - 1, prev, prevCount)
                return min(keepCount, deleteCount)
        return dfs(0, k, '', 0)
