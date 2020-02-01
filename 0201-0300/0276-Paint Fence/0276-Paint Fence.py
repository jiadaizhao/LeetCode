class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return k
        dp0 = k
        dp1 = k * k
        for i in range(3, n + 1):
            dp2 = (dp0 + dp1) * (k - 1)
            dp0 = dp1
            dp1 = dp2
        return dp1
