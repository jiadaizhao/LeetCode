class Solution:
    def sumSubseqWidths(self, A: List[int]) -> int:
        MOD = 10 ** 9 + 7
        A.sort()
        total = 0
        c = 1
        for i in range(len(A)):
            total = (total + A[i] * c - A[len(A) - i - 1] * c) % MOD
            c = (c * 2) % MOD
        return total
