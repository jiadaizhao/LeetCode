class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxNum1 = maxNum2 = 0
        for num in nums:
            if num > maxNum1:
                maxNum2 = maxNum1
                maxNum1 = num
            elif num > maxNum2:
                maxNum2 = num
        return (maxNum1 - 1) * (maxNum2 - 1)
