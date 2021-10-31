class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [[0] * 6 for _ in range(n + 1)]
        dp[0] = [1] * 6
        for i in range(1, n + 1):
            for j in range(1, 6):
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
        return dp[n][5]
