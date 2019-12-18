class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        dp = [[0] * len(s) for _ in range(len(s))]
        for j in range(len(dp)):
            dp[j][j] = 1
            for i in range(j - 1, -1, -1):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i + 1][j - 1]
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
        return dp[0][-1] >= len(s) - k
