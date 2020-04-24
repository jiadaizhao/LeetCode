class Solution:
    def numOfWays(self, n: int) -> int:
        dp2Color = 6
        dp3Color = 6
        MOD = 10 ** 9 + 7
        for i in range(1, n):
            temp = dp2Color
            dp2Color = (dp2Color * 3 + dp3Color * 2) % MOD
            dp3Color = (temp * 2 + dp3Color * 2) % MOD
        return (dp2Color + dp3Color) % MOD
