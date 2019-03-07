class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])
        result = []
        rowStart = 0
        rowEnd = m - 1
        colStart = 0
        colEnd = n - 1
        while rowStart <= rowEnd and colStart <= colEnd:
            for j in range(colStart, colEnd + 1):
                result.append(matrix[rowStart][j])
            rowStart += 1
            for i in range(rowStart, rowEnd + 1):
                result.append(matrix[i][colEnd])
            colEnd -= 1
            if rowStart <= rowEnd:
                for j in range(colEnd, colStart - 1, -1):
                    result.append(matrix[rowEnd][j])
                rowEnd -= 1
                
            if colStart <= colEnd:
                for i in range(rowEnd, rowStart - 1, -1):
                    result.append(matrix[i][colStart])
                colStart += 1
        return result
