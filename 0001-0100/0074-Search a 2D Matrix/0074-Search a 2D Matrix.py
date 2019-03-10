class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False

        low = 0
        high = len(matrix) * len(matrix[0])
        while low < high:
            mid = (low + high) // 2
            row = mid // len(matrix[0])
            col = mid % len(matrix[0])
            if matrix[row][col] < target:
                low = mid + 1
            elif matrix[row][col] > target:
                high = mid
            else:
                return True
        
        return False
