class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0] * (len(text2) + 1) for _ in range(2)]
        for i in range(1, 1 + len(text1)):
            for j in range(1, 1 + len(text2)):
                if text1[i - 1] == text2[j - 1]:
                    dp[i&1][j] = dp[(i - 1) & 1][j - 1] + 1
                else:
                    dp[i&1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j - 1])
        return dp[len(text1) & 1][len(text2)]
