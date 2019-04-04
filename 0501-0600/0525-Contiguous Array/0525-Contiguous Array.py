class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count = maxLen = 0
        table = {0:-1}
        for i, num in enumerate(nums):
            count += 1 if num else -1
            if count in table:
                maxLen = max(maxLen, i - table[count])
            else:
                table[count] = i
        return maxLen
