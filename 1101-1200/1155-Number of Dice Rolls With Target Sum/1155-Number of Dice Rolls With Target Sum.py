class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        dp = [[0] * (1 + target) for _ in range(1 + d)]
        dp[0][0] = 1
        MOD = 10 ** 9 + 7
        for i in range(1, 1 + d):
            for j in range(1, 1 + target):
                for k in range(1, 1 + min(f, j)):
                    dp[i][j] =  (dp[i][j] + dp[i - 1][j - k]) % MOD
        
        return dp[d][target]


class Solution2:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        dp = [0] * (1 + target)
        dp[0] = 1
        MOD = 10 ** 9 + 7
        for i in range(1, 1 + d):
            temp = [0] * (1 + target)
            for j in range(1, 1 + target):
                for k in range(1, 1 + min(f, j)):
                    temp[j] = (temp[j] + dp[j - k]) % MOD
            dp = temp
        
        return dp[target]
