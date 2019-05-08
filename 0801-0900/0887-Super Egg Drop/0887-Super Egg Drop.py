'''
The floor number we can check given m moves and k eggs.
dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1
'''

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        dp = [0] * (K + 1)
        m = 0
        while dp[K] < N:
            for k in range(K, 0, -1):
                dp[k] = dp[k - 1] + dp[k] + 1
            m += 1
        return m
