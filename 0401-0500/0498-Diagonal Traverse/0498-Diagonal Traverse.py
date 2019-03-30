class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        result = [0] * (len(matrix)*len(matrix[0]))
        row = col = 0
        for i in range(len(result)):
            result[i] = matrix[row][col]
            if (row + col)&1:
                if row == len(matrix) - 1:
                    col += 1
                elif col == 0:
                    row += 1
                else:
                    row += 1
                    col -= 1
            else:
                if col == len(matrix[0]) - 1:
                    row += 1
                elif row == 0:
                    col += 1
                else:
                    row -= 1
                    col += 1
        return result
