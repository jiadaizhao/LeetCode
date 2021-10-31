class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target = sum(nums) - x
        if target == 0:
            return len(nums)
        if target < 0:
            return -1
        table = {0 : -1}
        curr = 0
        maxLen = -1
        for i, num in enumerate(nums):
            curr += num
            if curr - target in table:
                maxLen = max(maxLen, i - table[curr - target])
            table[curr] = i
        return -1 if maxLen == -1 else len(nums) - maxLen
