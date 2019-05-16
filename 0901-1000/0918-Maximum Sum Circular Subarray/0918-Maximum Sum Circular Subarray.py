import math
class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        maxSum = -math.inf
        total = currMax = currMin = minSum = 0
        for a in A:
            if currMax < 0:
                currMax = 0
            currMax += a
            if currMin > 0:
                currMin = 0
            currMin += a
            total += a
            maxSum = max(maxSum, currMax)
            minSum = min(minSum, currMin)
        if minSum != total:
            maxSum = max(maxSum, total - minSum)
        return maxSum
