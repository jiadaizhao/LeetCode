# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        m, n = binaryMatrix.dimensions()
        row, col = 0, n - 1
        while row < m and col >= 0:
            if binaryMatrix.get(row, col) == 0:
                row += 1
            else:
                col -= 1
        
        return col + 1 if col != n - 1 else -1
