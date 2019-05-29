import collections
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        Q = collections.deque()
        fresh = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):               
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    Q.append((i, j))
        time = 0
        while fresh and Q:
            qs = len(Q)
            time += 1
            for _ in range(qs):
                row, col = Q.popleft()
                for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                    if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        fresh -= 1
                        Q.append((nr, nc))
        return time if fresh == 0 else -1
