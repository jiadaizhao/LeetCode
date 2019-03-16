import collections
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        Q = collections.deque()
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1':
                    count += 1
                    Q.append((i, j))
                    while Q:
                        r, c = Q.popleft()
                        for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                            if 0 <= nr < len(grid) and 0 <= nc < len(grid[i]) and grid[nr][nc] == '1':
                                grid[nr][nc] = '0'
                                Q.append((nr, nc))
        return count
