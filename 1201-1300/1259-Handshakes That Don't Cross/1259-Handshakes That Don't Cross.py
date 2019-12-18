class Solution:
    def numberOfWays(self, num_people: int) -> int:
        n = num_people // 2
        dp = [0] * (1 + n)
        dp[0] = 1
        MOD = 10 ** 9 + 7
        for i in range(1, 1 + n):
            for j in range(i):
                dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % MOD
        return dp[n]


# Catalan Number C(n, 2n) / (n + 1)
class Solution2:
    def numberOfWays(self, num_people: int) -> int:
        n = num_people // 2
        result = 1
        MOD = 10 ** 9 + 7
        for i in range(1, n + 1):
            result *= n + i
            result //= i
        return result // (n + 1) % MOD
