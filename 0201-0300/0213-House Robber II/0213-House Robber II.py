class Solution:
    def rob(self, nums: List[int]) -> int:
        def rob(start, end):
            dp0 = dp1 = 0
            for i in range(start, end + 1):
                dp2 = max(dp1, dp0 + nums[i])
                dp0 = dp1
                dp1 = dp2
            return dp1
        
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        else:
            return max(rob(0, len(nums) - 2), rob(1, len(nums) - 1))
