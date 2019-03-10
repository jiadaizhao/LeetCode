class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return

        firstRowHasZero = any(num == 0 for num in matrix[0])
        firstColHasZero = any(matrix[i][0] == 0 for i in range(len(matrix)))

        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0

        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if firstRowHasZero:
            for j in range(len(matrix[0])):
                matrix[0][j] = 0

        if firstColHasZero:
            for i in range(len(matrix)):
                matrix[i][0] = 0
