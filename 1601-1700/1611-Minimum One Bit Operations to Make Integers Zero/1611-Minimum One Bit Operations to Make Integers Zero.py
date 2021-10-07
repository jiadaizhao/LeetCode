from functools import lru_cache
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        @lru_cache(None)
        def dfs(n):
            if n == 0:
                return 0
            b = 1
            while (b << 1) <= n:
                b = b << 1
            return dfs((b >> 1) ^ b ^ n) + 1 + b - 1
        
        return dfs(n)
