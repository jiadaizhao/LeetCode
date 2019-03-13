class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dpMax = dpMin = maxP = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < 0:
                dpMax, dpMin = dpMin, dpMax
            dpMax = max(nums[i], dpMax*nums[i])
            dpMin = min(nums[i], dpMin*nums[i])
            maxP = max(maxP, dpMax)
        return maxP
