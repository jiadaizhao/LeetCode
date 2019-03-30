class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        total = sum(nums)
        if S > total or S < -total:
            return 0
        for i in range(len(nums)):
            nums[i] *= 2
        dp = [0] * (1 + S + total)
        dp[0] = 1
        for i in range(len(nums)):
            for j in range(S + total, nums[i] - 1, -1):
                dp[j] += dp[j - nums[i]]
        return dp[S + total]
