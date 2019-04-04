import collections
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
        table = collections.Counter(nums)
        if k == 0:
            return sum(val > 1 for val in table.values())
        
        count = 0
        for key, val in table.items():
            if key + k in table:
                count += 1
        return count
