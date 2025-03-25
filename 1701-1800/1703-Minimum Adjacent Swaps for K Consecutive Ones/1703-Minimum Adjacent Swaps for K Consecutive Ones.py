import math
class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        index = [i for i, v in enumerate(nums) if v == 1]
        n = len(index)
        presum = [0] * (n+1)
        for i in range(n):
            presum[i + 1] = presum[i] + index[i]

        minMove = math.inf

        if k & 1:
            radius = (k - 1) // 2
            for i in range(radius, n - radius):
                right = presum[i + radius + 1] - presum[i + 1]
                left = presum[i] - presum[i - radius]
                minMove = min(minMove, right - left)
            return minMove - radius * (radius + 1)
        else:
            radius = k // 2 - 1
            for i in range(radius, n - radius - 1):
                right = presum[i + radius + 2] - presum[i + 1]
                left = presum[i] -presum[i - radius]
                minMove = min(minMove, right - left - index[i])
            return minMove - radius * (radius + 1) - (radius + 1)
