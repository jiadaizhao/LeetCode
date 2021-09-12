class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        result = [0] * len(nums)
        curr = 0
        for i, num in enumerate(nums):
            curr += num
            result[i] = curr
        return result
