import collections
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        table = collections.Counter(arr)
        result = -1
        for k, v in table.items():
            if k == v:
                result = max(result, v)
        return result
