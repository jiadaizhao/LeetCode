class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        table = set(nums)
        maxLen = 0
        for num in nums:
            if num - 1 not in table:
                nextNum = num + 1
                while nextNum in table:
                    nextNum += 1
                maxLen = max(maxLen, nextNum - num)
        return maxLen
