class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        result = len(nums)
        for i, num in enumerate(nums):
            result ^= i ^ num
        return result

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return (len(nums) + 1)*len(nums)//2 - sum(nums)
