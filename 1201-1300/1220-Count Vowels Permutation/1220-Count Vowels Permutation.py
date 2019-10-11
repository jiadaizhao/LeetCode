class Solution:
    def countVowelPermutation(self, n: int) -> int:
        dp = [1] * 5
        MOD = 10 ** 9 + 7
        for _ in range(n - 1):
            temp = [0] * 5
            temp[0] = (dp[1] + dp[2] + dp[4]) % MOD
            temp[1] = (dp[0] + dp[2]) % MOD
            temp[2] = (dp[1] + dp[3]) % MOD
            temp[3] = dp[2]
            temp[4] = (dp[2] + dp[3]) % MOD
            dp = temp

        return sum(dp) % MOD
