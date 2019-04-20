class Solution:
    def numTilings(self, N: int) -> int:
        MOD = 1000000007
        dp = [0] * 1001
        '''
        dp[i] = dp[i - 1] + dp[i - 2] + 2 * (dp[i - 3] + dp[i - 4] + ... + dp[0])
        dp[i - 1] = dp[i - 2] + dp[i - 3] + 2 * (dp[i - 4] + dp[i - 4] + ... + dp[0])
        dp[i] - dp[i - 1] = dp[i - 1] + dp[i - 3]
        dp[i] = dp[i - 1]*2 + dp[i - 3]
        '''
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
        for i in range(3, N + 1):
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD
        return dp[N]
