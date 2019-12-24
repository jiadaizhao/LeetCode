class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        if not matrix:
            return
        m, n = len(matrix), len(matrix[0])
        self.mat = [[0] * n for _ in range(m)]
        self.bit = [[0] * (1 + n) for _ in range(1 + m)]
        for i in range(m):
            for j in range(n):
                self.update(i, j, matrix[i][j])

    def update(self, row: int, col: int, val: int) -> None:
        diff = val - self.mat[row][col]
        if diff != 0:
            self.mat[row][col] = val
            i = row + 1
            while i < len(self.bit):
                j = col + 1
                while j < len(self.bit[0]):
                    self.bit[i][j] += diff
                    j += (-j) & j
                i += (-i) & i

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.read(row2 + 1, col2 + 1) - self.read(row1, col2 + 1) - self.read(row2 + 1, col1) + self.read(row1, col1)

        
    def read(self, r, c):
        total = 0
        i = r
        while i > 0:
            j = c
            while j > 0:
                total += self.bit[i][j]
                j -= (-j) & j
            i -= (-i) & i
        return total
        

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
