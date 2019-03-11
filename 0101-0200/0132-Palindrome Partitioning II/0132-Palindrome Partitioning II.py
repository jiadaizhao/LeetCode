class Solution:
    def minCut(self, s: str) -> int:
        dp = [i - 1 for i in range(len(s) + 1)]
        for i in range(len(s)):
            j = 0
            while i - j >= 0 and i + j < len(s) and s[i - j] == s[i + j]:
                dp[i + j + 1] = min(dp[i + j + 1], 1 + dp[i - j])
                j += 1
                
            j = 1
            while i - j + 1 >= 0 and i + j < len(s) and s[i - j + 1] == s[i + j]:
                dp[i + j + 1] = min(dp[i + j + 1], 1 + dp[i - j + 1])
                j += 1
        return dp[-1]
