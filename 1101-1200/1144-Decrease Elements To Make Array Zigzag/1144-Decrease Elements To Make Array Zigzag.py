class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        move1 = move2 = 0
        for i in range(len(nums)):
            curr = max(nums[i] - min(nums[i - 1] - 1 if i > 0 else nums[i], nums[i + 1] - 1 if i < len(nums) - 1 else nums[i]), 0)
            if i & 1:
                move2 += curr
            else:
                move1 += curr
        return min(move1, move2)
