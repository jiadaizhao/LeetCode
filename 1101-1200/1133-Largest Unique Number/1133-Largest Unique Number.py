import collections
class Solution:
    def largestUniqueNumber(self, A: List[int]) -> int:
        table = collections.Counter(A)
        return max([k for k, v in table.items() if v == 1] or [-1])
