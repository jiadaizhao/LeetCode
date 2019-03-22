class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        dp = [[0] * (2 + len(nums)) for _ in range(2 + len(nums))]
            
        for l in range(1, 1 + len(nums)):
            for i in range(1, len(nums) - l + 2):
                j = i + l - 1
                for k in range(i, 1 + j):
                    left = nums[i - 2] if i > 1 else 1
                    right = nums[j] if j < len(nums) else 1
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + left * nums[k - 1] * right)
        return dp[1][len(nums)]
