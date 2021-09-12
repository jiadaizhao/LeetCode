import collections
class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        table = collections.Counter([a % k for a in arr])
        if table[0] & 1:
            return False
        for key in range(1, k // 2 + 1):
            if table[key] != table[k - key]:
                return False
        return True
