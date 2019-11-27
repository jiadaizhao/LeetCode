from functools import lru_cache
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        MOD = 10 ** 9 + 7
        @lru_cache(None)
        def dfs(pos, steps):
            if pos == 0 and steps == 0:
                return 1
            if pos < 0 or pos >= arrLen or pos > steps:
                return 0
            steps -= 1
            return (dfs(pos - 1, steps) + dfs(pos, steps) + dfs(pos + 1, steps)) % MOD
        return dfs(0, steps)
