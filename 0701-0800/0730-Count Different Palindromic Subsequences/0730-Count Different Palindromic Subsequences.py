class Solution:
    def countPalindromicSubsequences(self, S: str) -> int:
        n = len(S)
        MOD = 1000000007
        dp = [[[0]*n for _ in range(n)] for _ in range(4)]
        for i in range(n):
            for k in range(4):
                if ord(S[i]) == ord('a') + k:
                    dp[k][i][i] = 1
        
        for l in range(2, 1 + n):
            for i in range(n - l + 1):
                j = i + l - 1
                for k in range(4):
                    c = chr(ord('a') + k)
                    if S[i] != c:
                        dp[k][i][j] = dp[k][i + 1][j]
                    elif S[j] != c:
                        dp[k][i][j] = dp[k][i][j - 1]
                    else:
                        dp[k][i][j] = 2
                        if l != 2:
                            for m in range(4):
                                dp[k][i][j] = (dp[k][i][j] + dp[m][i + 1][j - 1]) % MOD
                                
        return sum(dp[k][0][n - 1] for k in range(4)) % MOD

# With preprocess
class Solution2:
    def countPalindromicSubsequences(self, S: str) -> int:
        n = len(S)
        MOD = 1000000007
        prev = [[-1]*4 for _ in range(n)]
        next = [[-1]*4 for _ in range(n)]
        dp = [[0]*n for _ in range(n)]
        last = [-1]*4
        for i in range(n):
            last[ord(S[i]) - ord('a')] = i
            for j in range(4):
                prev[i][j] = last[j]
                
        last = [-1]*4
        for i in range(n - 1, -1, -1):
            last[ord(S[i]) - ord('a')] = i
            for j in range(4):
                next[i][j] = last[j]
                
        def dfs(start, end):
            if start > end:
                return 0
            if dp[start][end]:
                return dp[start][end]
            count = 0
            for k in range(4):
                i = next[start][k]
                j = prev[end][k]
                if i == -1 or i > j:
                    continue
                if i == j:
                    count = (count + 1) % MOD
                else:
                    count = (count + 2 + dfs(i + 1, j - 1)) % MOD
            dp[start][end] = count
            return count
        
        return dfs(0, n - 1)

