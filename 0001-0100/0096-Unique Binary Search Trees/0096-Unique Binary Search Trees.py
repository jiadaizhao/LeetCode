class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        for j in range(1, n + 1):
            for i in range(j):
                dp[j] += dp[i] * dp[j - i - 1]
        return dp[n]


# Catalan Number
class Solution2:
    def numTrees(self, n: int) -> int:
        result = 1
        for i in range(1, n + 1):
            result *= n + i
            result //= i
        return result // (n + 1)
