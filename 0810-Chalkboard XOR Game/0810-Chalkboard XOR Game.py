class Solution:
    def xorGame(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        x = 0
        for num in nums:
            x ^= num
        return x == 0 or (len(nums) & 1) == 0
