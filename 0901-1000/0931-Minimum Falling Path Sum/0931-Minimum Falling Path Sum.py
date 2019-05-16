class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        for i in range(1, len(A)):
            for j in range(len(A[i])):
                prev = A[i - 1][j]
                if j > 0:
                    prev = min(prev, A[i - 1][j - 1])
                if j < len(A[i]) - 1:
                    prev = min(prev, A[i - 1][j + 1])
                A[i][j] += prev
        return min(A[-1])
