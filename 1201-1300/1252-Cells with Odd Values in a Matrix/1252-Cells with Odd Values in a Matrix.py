class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        rows = [False] * n
        cols = [False] * m
        countRow = countCol = 0
        for r, c in indices:
            rows[r] ^= True
            cols[c] ^= True
            countRow += 1 if rows[r] else -1
            countCol += 1 if cols[c] else -1
            
        return countRow * (m - countCol) + countCol * (n - countRow)
