class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        table = {0: -1}
        presum = maxLen = 0
        for i, num in enumerate(nums):
            presum += num
            if presum - k in table:
                maxLen = max(maxLen, i - table[presum - k])
            if presum not in table:
                table[presum] = i
        return maxLen
