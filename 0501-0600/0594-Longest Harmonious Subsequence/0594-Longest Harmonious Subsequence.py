import collections
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        table = collections.Counter(nums)
        maxCount = 0
        for num in table:
            if num + 1 in table:
                maxCount = max(maxCount, table[num] + table[num + 1])
        return maxCount
