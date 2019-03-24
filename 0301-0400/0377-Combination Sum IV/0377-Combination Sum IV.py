class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (1 + target)
        dp[0] = 1
        for i in range(1, 1 + target):
            for num in nums:
                if i >= num:
                    dp[i] += dp[i - num]
        return dp[target]
