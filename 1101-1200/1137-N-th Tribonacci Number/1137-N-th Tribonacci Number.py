class Solution:
    def tribonacci(self, n: int) -> int:
        if n <= 1:
            return n

        dp0 = 0
        dp1 = 1
        dp2 = 1
        for i in range(3, n + 1):
            dp3 = dp0 + dp1 + dp2
            dp0 = dp1
            dp1 = dp2
            dp2 = dp3
        return dp2
