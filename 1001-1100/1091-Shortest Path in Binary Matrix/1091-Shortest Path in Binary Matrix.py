import collections
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] or grid[-1][-1]:
            return -1
        Q = collections.deque([(0, 0)])
        grid[0][0] = 1
        step = 0
        while Q:
            step += 1
            for _ in range(len(Q)):
                r, c = Q.popleft()
                if r == len(grid) - 1 and c == len(grid[0]) - 1:
                    return step
                for nr, nc in (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1):
                    if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] == 0:
                        Q.append((nr, nc))
                        grid[nr][nc] = 1
                        
        return -1
