class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        result = [[0]*n for _ in range(n)]
        rowStart = colStart = 0
        rowEnd = colEnd = n - 1
        num = 1
        while rowStart <= rowEnd and colStart <= colEnd:
            for j in range(colStart, colEnd + 1):
                result[rowStart][j] = num
                num += 1
            rowStart += 1
            for i in range(rowStart, rowEnd + 1):
                result[i][colEnd] = num
                num += 1
            colEnd -= 1
            if rowStart <= rowEnd:
                for j in range(colEnd, colStart - 1, -1):
                    result[rowEnd][j] = num
                    num += 1
                rowEnd -= 1
                
            if colStart <= colEnd:
                for i in range(rowEnd, rowStart - 1, -1):
                    result[i][colStart] = num
                    num += 1
                colStart += 1
        return result
