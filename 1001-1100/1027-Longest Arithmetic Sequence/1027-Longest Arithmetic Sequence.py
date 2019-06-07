class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        table = {}
        for j in range(len(A)):
            for i in range(j):
                table[j, A[j] - A[i]] = table.get((i, A[j] - A[i]), 1) + 1
        return max(table.values())
