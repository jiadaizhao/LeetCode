class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        count = 0
        table = {r : i for i, r in enumerate(row)}
        for i in range(0, len(row), 2):
            couple = row[i] ^ 1
            ci = table[couple]
            if ci != i + 1:
                count += 1
                table[row[i + 1]] = ci
                row[i + 1], row[ci] = row[ci], row[i + 1]
                table[couple] = i + 1
        return count
