class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxLen = start = zero = 0
        for i, num in enumerate(nums):
            if num == 0:
                zero += 1
            while zero > 1:
                if nums[start] == 0:
                    zero -= 1
                start += 1
            maxLen = max(maxLen, i - start)
        return maxLen
