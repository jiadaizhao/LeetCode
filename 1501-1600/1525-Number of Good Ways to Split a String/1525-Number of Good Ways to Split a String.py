import collections
class Solution:
    def numSplits(self, s: str) -> int:
        table1 = collections.Counter()
        table2 = collections.Counter(s)
        count = 0
        for c in s:
            table1[c] += 1
            table2[c] -= 1
            if table2[c] == 0:
                del table2[c]
            if len(table1) == len(table2):
                count += 1
        return count
