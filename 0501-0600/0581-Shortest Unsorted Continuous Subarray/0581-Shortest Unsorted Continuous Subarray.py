import math

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        snums = sorted(nums)
        l = 0
        while l < len(nums):
            if nums[l] != snums[l]:
                break
            l += 1
        if l == len(nums):
            return 0
        r = len(nums) - 1
        while r >= 0:
            if nums[r] != snums[r]:
                break
            r -= 1
        return r - l + 1 if r >= l else 0

class Solution2:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        l = 0
        r = -1
        maxNum = nums[0]
        minNum = nums[-1]
        for i in range(1, len(nums)):
            maxNum = max(maxNum, nums[i])
            minNum = min(minNum, nums[-i-1])
            if nums[i] < maxNum:
                r = i
            if nums[-i-1] > minNum:
                l = len(nums) - i - 1
        return r - l + 1
