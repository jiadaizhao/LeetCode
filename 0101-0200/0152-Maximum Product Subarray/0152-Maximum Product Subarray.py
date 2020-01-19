class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dpMax = dpMin = maxP = nums[0]
        for num in nums[1:]:
            if num < 0:
                dpMax, dpMin = dpMin, dpMax
            dpMax = max(num, dpMax * num)
            dpMin = min(num, dpMin * num)
            maxP = max(maxP, dpMax)

        return maxP
