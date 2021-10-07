class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n = len(heights), len(heights[0])
        def dfs(r, c, threshold):
            if r == m - 1 and c == n - 1:
                return True
            for nr, nc in (r-1,c),(r+1,c),(r,c-1),(r,c+1):
                if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc] and abs(heights[nr][nc] - heights[r][c]) <= threshold:
                    visited[nr][nc] = True
                    if dfs(nr, nc, threshold):
                        return True
            return False
        
        low, high = 0, max(map(max, heights)) - min(map(min, heights))
        while low < high:
            mid = (low + high) // 2
            visited = [[False] * n for _ in range(m)]
            if dfs(0, 0, mid):
                high = mid
            else:
                low = mid + 1
        return low
