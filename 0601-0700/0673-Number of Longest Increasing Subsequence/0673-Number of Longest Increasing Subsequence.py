class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        dp = [1] * len(nums)
        count = [1] * len(nums)
        maxLen = total = 1
        for j in range(1, len(nums)):
            for i in range(j):
                if nums[j] > nums[i]:
                    if 1 + dp[i] > dp[j]:
                        dp[j] = 1 + dp[i]
                        count[j] = count[i]
                    elif 1 + dp[i] == dp[j]:
                        count[j] += count[i]
            if dp[j] > maxLen:
                maxLen = dp[j]
                total = count[j]
            elif dp[j] == maxLen:
                total += count[j]
        return total
