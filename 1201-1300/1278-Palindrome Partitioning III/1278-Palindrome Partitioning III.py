class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        cost = [[0] * n for _ in range(n)]
        for j in range(1, n):
            for i in range(j - 1, -1, -1):
                if s[i] == s[j]:
                    cost[i][j] = cost[i + 1][j - 1]
                else:
                    cost[i][j] = 1 + cost[i + 1][j - 1]
        
        dp = [[0] * n for _ in range(1 + k)]
        for j in range(n):
            dp[1][j] = cost[0][j]
            
        for l in range(2, 1 + k):
            for j in range(l - 1, n):
                dp[l][j] = j + 1
                for i in range(j):
                    dp[l][j] = min(dp[l][j], dp[l - 1][i] + cost[i + 1][j])
        return dp[k][n - 1]


# Optimize space
class Solution2:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        cost = [[0] * n for _ in range(n)]
        for j in range(1, n):
            for i in range(j - 1, -1, -1):
                if s[i] == s[j]:
                    cost[i][j] = cost[i + 1][j - 1]
                else:
                    cost[i][j] = 1 + cost[i + 1][j - 1]
        
        dp =[0] * n
        for j in range(n):
            dp[j] = cost[0][j]
            
        for l in range(2, 1 + k):
            temp = [0] * n
            for j in range(l - 1, n):
                temp[j] = j + 1 
                for i in range(j):
                    temp[j] = min(temp[j], dp[i] + cost[i + 1][j])
            dp = temp
        return dp[n - 1]
