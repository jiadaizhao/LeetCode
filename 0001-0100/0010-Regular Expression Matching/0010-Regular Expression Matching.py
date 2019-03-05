class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False]*(len(p) + 1) for _ in range(len(s) + 1)]
        dp[0][0] = True
        for j in range(2, len(p) + 1):
            if p[j - 1] == '*' and dp[0][j - 2]:
                dp[0][j] = True
        
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if (s[i - 1] == p[j - 1] or p[j - 1] == '.') and dp[i - 1][j - 1]:
                    dp[i][j] = True
                elif p[j - 1] == '*':
                    if j > 1 and dp[i][j - 2]:
                        dp[i][j] = True
                    elif j > 1 and (s[i - 1] == p[j - 2] or p[j - 2] == '.') and dp[i - 1][j]:
                        dp[i][j] = True
        return dp[-1][-1]
