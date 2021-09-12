import collections
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        table = collections.Counter(arr)
        count = collections.Counter(table.values())
        result = len(table)
        for c in range(1, len(arr) + 1):
            if c * count[c] <= k:
                result -= count[c]
                k -= c * count[c]
            else:
                break
        return result - k // c
