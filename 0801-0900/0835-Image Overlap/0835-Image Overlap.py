import collections

class Solution:
    def largestOverlap(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: int
        """
        n = len(A)
        A1 = [i * n + j for i in range(n) for j in range(n) if A[i][j]]
        B1 = [i * n + j for i in range(n) for j in range(n) if B[i][j]]
        table = collections.Counter(i - j for i in A1 for j in B1)
        return max(table.values() or [0])
