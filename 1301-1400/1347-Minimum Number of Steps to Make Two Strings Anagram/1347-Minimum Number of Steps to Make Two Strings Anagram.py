import collections
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        table = collections.Counter(s) - collections.Counter(t)
        return sum(table.values())
