class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        skip = [[0] * 10 for _ in range(10)]
        skip[1][3] = skip[3][1] = 2
        skip[1][7] = skip[7][1] = 4
        skip[3][9] = skip[9][3] = 6
        skip[7][9] = skip[9][7] = 8
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5
        visited = [False] * 10
        def dfs(curr, remain):
            if remain == 0:
                return 1
            remain -= 1
            count = 0
            visited[curr] = True
            for i in range(1, 10):
                if not visited[i] and (skip[curr][i] == 0 or visited[skip[curr][i]]):
                    count += dfs(i, remain)
            visited[curr] = False
            return count
        
        count = 0
        for i in range(m, n + 1):
            count += dfs(1, i - 1) * 4
            count += dfs(2, i - 1) * 4
            count += dfs(5, i - 1)

        return count        
