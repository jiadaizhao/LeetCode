import collections
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        return max(collections.Counter(tuple(x ^ row[0] for x in row) for row in matrix).values())
