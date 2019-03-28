class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        dp = [[0]*len(nums) for _ in range(len(nums))]
        for i in range(len(nums)):
            dp[i][i] = nums[i]
            
        for l in range(2, len(nums) + 1):
            for i in range(len(nums) - l + 1):
                j = i + l - 1
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
        return dp[0][-1] >= 0
