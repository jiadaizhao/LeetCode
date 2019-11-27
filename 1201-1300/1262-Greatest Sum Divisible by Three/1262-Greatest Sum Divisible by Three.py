import math
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, -math.inf, -math.inf]
        for num in nums:
            temp = [0] * 3
            for i in range(3):
                temp[(i + num) % 3] = max(dp[(i + num) % 3], dp[i] + num)
            dp = temp
        return dp[0]
