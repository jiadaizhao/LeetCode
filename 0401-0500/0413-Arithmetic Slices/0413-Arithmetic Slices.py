class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        total = count = 0
        for i in range(2, len(A)):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                count += 1
            else:
                total += count * (count + 1) // 2
                count = 0
        total += count * (count + 1) // 2
        return total
