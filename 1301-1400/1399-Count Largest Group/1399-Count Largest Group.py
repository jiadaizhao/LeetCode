import collections
class Solution:
    def countLargestGroup(self, n: int) -> int:
        table = collections.Counter()
        for i in range(1, n + 1):
            sd = 0
            while i:
                sd += i % 10
                i //= 10
            table[sd] += 1
        largestSize = max(table.values())
        return sum(v == largestSize for v in table.values())
