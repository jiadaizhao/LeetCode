class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        nums.sort()
        maxNum = 1
        maxIndex = 0
        parent = [0] * len(nums)
        dp = [1] * len(nums)
        for j in range(1, len(nums)):
            for i in range(j):
                if nums[j] % nums[i] == 0 and 1 + dp[i] > dp[j]:
                    parent[j] = i
                    dp[j] = 1 + dp[i]
                    if dp[j] > maxNum:
                        maxNum = dp[j]
                        maxIndex = j
            
        result = [0] * maxNum
        for i in range(maxNum - 1, -1, -1):
            result[i] = nums[maxIndex]
            maxIndex = parent[maxIndex]
        return result
