class Solution:
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """
        if K == 0:
            return 1
        presum = [0] * (1 + N)
        presum[0] = 1
        for i in range(1, len(presum)):
            presum[i] = presum[i - 1]
            if i > W:
                presum[i] += (presum[i - 1] - presum[i - 1 - W]) / W
            else:
                presum[i] += presum[i - 1] / W
            if i > K:
                presum[i] -= (presum[i - 1] - presum[K - 1]) / W
        return presum[N] - presum[K - 1]
