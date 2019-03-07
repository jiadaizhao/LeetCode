import math
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = -math.inf
        curr = 0
        for num in nums:
            curr += num
            maxSum = max(maxSum, curr)
            curr = max(curr, 0)
        return maxSum
