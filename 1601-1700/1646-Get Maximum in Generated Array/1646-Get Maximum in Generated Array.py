class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n <= 1:
            return n
        nums = [0] * (n + 1)
        nums[1] = maxNum = 1
        for i in range(2, n + 1):
            if i & 1:
                nums[i] = nums[i // 2] + nums[i // 2 + 1]
            else:
                nums[i] = nums[i // 2]
            maxNum = max(maxNum, nums[i])
        return maxNum
