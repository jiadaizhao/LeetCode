class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m = len(s1)
        n = len(s2)
        dp = [[0] * (1 + n) for _ in range(m + 2)]
        for j in range(1, n + 1):
            dp[0][j] = dp[0][j - 1] + ord(s2[j - 1])
        
        for i in range(1, m + 1):
            dp[i][0] = dp[i - 1][0] + ord(s1[i - 1])
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j] + ord(s1[i - 1]), dp[i][j - 1] + ord(s2[j - 1]))
        return dp[m][n]


# Optimize space
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m = len(s1)
        n = len(s2)
        dp = [0] * (1 + n)
        for j in range(1, n + 1):
            dp[j] = dp[j - 1] + ord(s2[j - 1])
            
        for i in range(1, m + 1):
            temp = [0] * (1 + n)
            temp[0] = dp[0] + ord(s1[i - 1])
            for j in range(1, 1 + n):
                if s1[i - 1] == s2[j - 1]:
                    temp[j] = dp[j - 1]
                else:
                    temp[j] = min(dp[j] + ord(s1[i - 1]), temp[j - 1] + ord(s2[j - 1]))
            dp = temp
        return dp[-1]
