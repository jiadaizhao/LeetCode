class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        total = minSum = 0
        for num in nums:
            total += num
            minSum = min(minSum, total)
        return 1 - minSum
