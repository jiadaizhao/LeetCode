import collections
class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        table = collections.Counter(min(a, b) for a, b in rectangles)
        return table[max(table.keys())]
