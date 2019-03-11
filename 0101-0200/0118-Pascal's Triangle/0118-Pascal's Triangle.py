class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = []
        for i in range(numRows):
            row = [1] * (1 + i)
            for j in range(1, i):
                row[j] = result[-1][j - 1] + result[-1][j]
            result.append(row)
        return result
