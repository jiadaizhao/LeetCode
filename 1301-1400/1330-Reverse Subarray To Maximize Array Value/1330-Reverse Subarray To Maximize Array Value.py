import math
class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
        total = change = 0
        min1, max1 = math.inf, -math.inf
        for a, b in zip(nums, nums[1:]):
            total += abs(a - b)
            change = max(change, abs(nums[0] - b) - abs(a - b), abs(nums[-1] - a) - abs(a - b))
            min1 = min(min1, max(a, b))
            max1 = max(max1, min(a, b))

        return total + max(change, (max1 - min1) * 2)
