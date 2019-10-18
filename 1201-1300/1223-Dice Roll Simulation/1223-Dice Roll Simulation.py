from functools import lru_cache
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = 10 ** 9 + 7
        @lru_cache(None)
        def dfs(prevSame, curr, left):
            if left == 0:
                return 1
            total = 0
            for i in range(6):
                if curr != i:
                    total = (total + dfs(1, i, left - 1)) % MOD
                elif prevSame < rollMax[i]:
                    total = (total + dfs(prevSame + 1, i, left - 1)) % MOD

            return total

        return dfs(0, 0, n)


class Solution2:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = 10 ** 9 + 7
        dp = [[1] * 7 for _ in range(n)]
        dp[0][6] = 6
        for i in range(1, n):
            total = 0
            for j in range(6):
                dp[i][j] = dp[i - 1][6]
                if i > rollMax[j]:
                    reduction = (dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j]) % MOD
                    dp[i][j] = (dp[i][j] - reduction) % MOD
                elif i == rollMax[j]:
                    dp[i][j] = (dp[i][j] - 1) % MOD
                total = (total + dp[i][j]) % MOD
            dp[i][6] = total

        return dp[n - 1][6]
