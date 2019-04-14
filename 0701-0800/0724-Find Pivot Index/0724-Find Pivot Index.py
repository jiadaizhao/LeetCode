class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        s = sum(nums)
        leftSum = 0
        for i, num in enumerate(nums):
            if leftSum == s - leftSum - num:
                return i
            leftSum += num
        return -1
