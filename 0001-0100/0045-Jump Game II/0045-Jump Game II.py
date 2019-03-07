class Solution:
    def jump(self, nums: List[int]) -> int:
        maxIndex = currMax = count = 0
        for i in range(len(nums) - 1):
            currMax = max(currMax, i + nums[i])
            if i == maxIndex:
                count += 1
                maxIndex = currMax
        return count
