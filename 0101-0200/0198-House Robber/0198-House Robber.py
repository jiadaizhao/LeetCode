class Solution:
    def rob(self, nums: List[int]) -> int:
        dp0 = dp1 = 0
        for num in nums:
            dp2 = max(dp1, dp0 + num)
            dp0 = dp1
            dp1 = dp2
        return dp1
