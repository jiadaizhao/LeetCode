class Solution:
    def numPermsDISequence(self, S: str) -> int:
        MOD = 10 ** 9 + 7
        n = len(S)
        # dp[i][j] means number of the length i, ending with j
        dp = [[0] * (n + 1) for _ in range(n + 2)]
        dp[1][0] = 1
        for i in range(2, n + 2):
            for j in range(i):
                if S[i - 2] == 'D':
                    dp[i][j] = (sum(dp[i - 1][k] for k in range(j, i))) % MOD
                else:
                    dp[i][j] = (sum(dp[i - 1][k] for k in range(j))) % MOD

        return sum(dp[n + 1][i] for i in range(n + 1)) % MOD


# use presum idea to optimize to O(n^2)
class Solution2:
    def numPermsDISequence(self, S: str) -> int:
        MOD = 10 ** 9 + 7
        n = len(S)
        # dp[i][j] means presum of length i, ending from 0 to j
        dp = [[0] * (n + 2) for _ in range(n + 2)]
        for j in range(n + 2):
            dp[1][j] = 1

        for i in range(2, n + 2):
            for j in range(i):
                if S[i - 2] == 'D':
                    if j > 0:
                        dp[i][j] = (dp[i][j - 1] + (dp[i - 1][i - 1] - dp[i - 1][j - 1])) % MOD
                    else:
                        dp[i][j] = dp[i - 1][i - 1]
                else:
                    if j > 0:
                        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD
            dp[i][i] = dp[i][i - 1]
        
        return dp[n + 1][n]
