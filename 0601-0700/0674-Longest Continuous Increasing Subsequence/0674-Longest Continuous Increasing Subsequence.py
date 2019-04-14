class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        start = maxLen = 0
        for i in range(1, len(nums) + 1):
            if i == len(nums) or nums[i] <= nums[i - 1]:
                maxLen = max(maxLen, i - start)
                start = i
        return maxLen
