import collections
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        table = collections.Counter(arr)
        return len(table) == len(set(table.values()))
