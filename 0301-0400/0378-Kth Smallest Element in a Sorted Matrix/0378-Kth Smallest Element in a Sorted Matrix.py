class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        low = matrix[0][0]
        high = matrix[-1][-1]
        while low < high:
            mid = (low + high) // 2
            count = 0
            row = len(matrix) - 1
            col = 0
            while row >= 0 and col < len(matrix):
                if matrix[row][col] > mid:
                    row -= 1
                else:
                    count += row + 1
                    col += 1

            if count < k:
                low = mid + 1
            else:
                high = mid
        
        return low
