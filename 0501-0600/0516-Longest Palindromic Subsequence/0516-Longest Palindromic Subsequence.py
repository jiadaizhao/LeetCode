class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        if not s:
            return 0
        dp = [[0]*len(s) for _ in range(len(s))]
        for j in range(len(s)):
            dp[j][j] = 1
            for i in range(j - 1, -1, -1):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i + 1][j - 1]
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][-1]
