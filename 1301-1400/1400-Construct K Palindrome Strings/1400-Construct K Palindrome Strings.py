import collections
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if k > len(s):
            return False
        table = collections.Counter(s)
        oddCount = sum(v & 1 for v in table.values())
        return oddCount <= k
