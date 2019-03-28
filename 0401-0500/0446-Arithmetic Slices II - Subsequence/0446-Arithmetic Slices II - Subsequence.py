import collections
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        count = 0
        table = [collections.Counter() for _ in range(len(A))]
        for j in range(1, len(A)):
            for i in range(j):
                diff = A[j] - A[i]
                table[j][diff] += 1
                if diff in table[i]:
                    table[j][diff] += table[i][diff]
                    count += table[i][diff]
        return count
