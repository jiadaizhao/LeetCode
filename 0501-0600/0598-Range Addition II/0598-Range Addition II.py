class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        for op in ops:
            m = min(m, op[0])
            n = min(n, op[1])
        return m * n
