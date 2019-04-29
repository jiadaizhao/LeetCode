import collections
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        A1 = [i * len(A) * 2 + j for i in range(len(A)) for j in range(len(A)) if A[i][j]]
        B1 = [i * len(A) * 2 + j for i in range(len(A)) for j in range(len(A)) if B[i][j]]
        table = collections.Counter(i - j for i in A1 for j in B1)
        return max(table.values() or [0])
