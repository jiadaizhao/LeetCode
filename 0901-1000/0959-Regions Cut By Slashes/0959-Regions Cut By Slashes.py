class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        N = len(grid)
        graph = [[0] * (N*3) for _ in range(N*3)]
        for i in range(N):
            for j in range(N):
                if grid[i][j] == '/':
                    graph[i*3][j*3 + 2] = graph[i*3 + 1][j*3 + 1] = graph[i*3 + 2][j*3] = 1
                elif grid[i][j] == '\\':
                    graph[i*3][j*3] = graph[i*3 + 1][j*3 + 1] = graph[i*3 + 2][j*3 + 2] = 1
                    
        region = 0
        def dfs(row, col):
            if 0 <= row < len(graph) and 0 <= col < len(graph) and graph[row][col] == 0:
                graph[row][col] = 1
                dfs(row - 1, col)
                dfs(row + 1, col)
                dfs(row, col - 1)
                dfs(row, col + 1)
                
        for i in range(len(graph)):
            for j in range(len(graph)):
                if graph[i][j] == 0:
                    dfs(i, j)
                    region += 1
        return region
