import collections
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        table = collections.Counter()
        total = 0
        for num in nums:
            total += table[num]
            table[num] += 1
        return total
