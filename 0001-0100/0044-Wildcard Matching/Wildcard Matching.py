class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        dp = [[False]*(1 + n) for _ in range(1 + m)]
        dp[0][0] = True
        for j in range(1, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = True
            else:
                break
                
        for i in range(1, 1 + m):
            for j in range(1, 1 + n):
                if (s[i - 1] == p[j - 1] or p[j - 1] == '?') and dp[i - 1][j - 1]:
                    dp[i][j] = True
                elif p[j - 1] == '*' and (dp[i][j - 1] or dp[i - 1][j]):
                    dp[i][j] = True
        return dp[-1][-1]
