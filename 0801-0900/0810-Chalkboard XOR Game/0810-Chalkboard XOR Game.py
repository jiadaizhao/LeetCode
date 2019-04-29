class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        x = 0
        for num in nums:
            x ^= num
        return x == 0 or (len(nums) & 1) == 0
