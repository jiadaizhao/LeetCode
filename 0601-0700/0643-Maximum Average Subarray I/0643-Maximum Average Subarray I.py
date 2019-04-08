class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        s = sum(nums[:k])
        maxSum = s
        for i in range(k, len(nums)):
            s += nums[i] - nums[i - k]
            maxSum = max(maxSum, s)
        return maxSum / k
