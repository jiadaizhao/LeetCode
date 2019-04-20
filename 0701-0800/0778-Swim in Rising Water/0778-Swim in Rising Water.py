import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        N = len(grid)
        pq = [(grid[0][0], 0, 0)]
        t = 0
        visited = set([0])
        while pq:
            val, row, col = heapq.heappop(pq)
            t = max(t, val)
            if row == N - 1 and col == N - 1:
                break
            for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                if 0 <= nr < N and 0 <= nc < N and nr * N + nc not in visited:
                    heapq.heappush(pq, (grid[nr][nc], nr, nc))
                    visited.add(nr * N + nc)
        return t
