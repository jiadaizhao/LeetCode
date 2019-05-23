import collections
class Solution:
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        table = collections.Counter(A)
        keys = list(table.keys())
        keys.sort(key=abs)
        for key in keys:
            if table[key] > table[key * 2]:
                return False
            table[key * 2] -= table[key]
        return True
