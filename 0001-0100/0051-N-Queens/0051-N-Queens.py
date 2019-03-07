class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        flags_col = [1] * n
        flags_45 = [1] * (2*n - 1)
        flags_135 = [1] * (2*n - 1)
        result = []
        queens = [['.']*n for _ in range(n)]
        def dfs(row):
            if row == n:
                result.append([''.join(q) for q in queens])
                return
            
            for col in range(n):
                if flags_col[col] and flags_45[row + col] and flags_135[row - col + n - 1]:
                    queens[row][col] = 'Q'
                    flags_col[col] = flags_45[row + col] = flags_135[row - col + n - 1] = 0
                    dfs(row + 1)
                    flags_col[col] = flags_45[row + col] = flags_135[row - col + n - 1] = 1
                    queens[row][col] = '.'
        dfs(0)
        return result
