class Solution:
    def findDerangement(self, n: int) -> int:
        if n == 1:
            return 0
        MOD = 10 ** 9 + 7
        dp1 = 0
        dp2 = 1
        for i in range(3, n + 1):
            dp3 = (i - 1) * (dp1 + dp2) % MOD
            dp1 = dp2
            dp2 = dp3
        return dp2
