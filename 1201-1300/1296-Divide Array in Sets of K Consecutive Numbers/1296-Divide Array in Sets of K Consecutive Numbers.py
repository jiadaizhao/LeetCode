import collections
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k:
            return False

        table = collections.Counter(nums)
        for key in sorted(table):
            if table[key] > 0:
                need = table[key]
                for i in range(key, key + k):                    
                    if table[i] < need:
                        return False
                    table[i] -= need
        return True
