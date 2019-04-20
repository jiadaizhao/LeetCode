import collections
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        table = collections.Counter(T)
        result = []
        for c in S:
            if c in table:
                result.append(c*table[c])
                table[c] = 0
        for c, v in table.items():
            if v > 0:
                result.append(c*v)
        return ''.join(result)
