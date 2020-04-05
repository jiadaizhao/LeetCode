import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        pq = [(matrix[0][0], 0, 0)]
        while k > 0:
            result, row, col = heapq.heappop(pq)
            if row < len(matrix) - 1:
                heapq.heappush(pq, (matrix[row + 1][col], row + 1, col))
            if row == 0 and col < len(matrix[0]) - 1:
                heapq.heappush(pq, (matrix[row][col + 1], row, col + 1))
            k -= 1
        return result


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        low, high = matrix[0][0], matrix[-1][-1]
        while low < high:
            mid = (low + high) // 2
            count = col = 0
            row = len(matrix) - 1
            while row >= 0 and col < len(matrix[0]):
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
