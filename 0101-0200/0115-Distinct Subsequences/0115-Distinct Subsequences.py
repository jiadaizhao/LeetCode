class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = [0] * (1 + len(t))
        dp[0] = 1
        for i in range(1, len(s) + 1):
            for j in range(len(t), 0, -1):
                if s[i - 1] == t[j - 1]:
                    dp[j] += dp[j - 1]
        return dp[-1]
