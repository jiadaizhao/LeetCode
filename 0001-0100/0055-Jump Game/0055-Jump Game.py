class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxIndex = 0
        for i, num in enumerate(nums):
            if maxIndex < i:
                break
            maxIndex = max(maxIndex, i + num)
        return maxIndex >= len(nums) - 1
