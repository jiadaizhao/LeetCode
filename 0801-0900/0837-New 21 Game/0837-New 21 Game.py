class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        if K == 0:
            return 1
        presum = [0] * (1 + N)
        presum[0] = 1
        for i in range(1, 1 + N):
            presum[i] = presum[i - 1]
            if i > W:
                presum[i] += (presum[i - 1] - presum[i - 1 - W]) / W
            else:
                presum[i] += presum[i - 1] / W
            if i > K:
                presum[i] -= (presum[i - 1] - presum[K - 1]) / W
        return presum[N] - presum[K - 1]


class Solution2:
    def new21Game(self, N: int, K: int, W: int) -> float:
        if K == 0:
            return 1
        dp = [0] * (1 + N)
        dp[0] = 1
        Wsum = 1
        total = 0
        for i in range(1, 1 + N):
            dp[i] = Wsum / W
            if i < K:
                Wsum += dp[i]
            else:
                total += dp[i]
            if i >= W:
                Wsum -= dp[i - W]
        return total
