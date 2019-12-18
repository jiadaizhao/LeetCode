# Bottom up TLE
class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
            
        for l in range(2, 1 + n):
            for i in range(0, n - l + 1):
                j = i + l - 1
                if arr[i] == arr[j]:
                    dp[i][j] = max(1, dp[i + 1][j - 1])
                else:
                    dp[i][j] = j - i + 1
                    for k in range(i, j):
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j])
                        
        return dp[0][-1]


# Top bottom
from functools import lru_cache
class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        @lru_cache(None)
        def dfs(i, j):
            if i > j:
                return 0
            if i == j:
                return 1
            result = dfs(i, j - 1) + 1
            if arr[j - 1] == arr[j]:
                result = min(result, dfs(i, j - 2) + 1)
            for k in range(i, j - 1):
                if arr[k] == arr[j]:
                    result = min(result, dfs(i, k - 1) + dfs(k + 1, j - 1))
            return result
        
        return dfs(0, len(arr) - 1)
