class Solution:
    def totalNQueens(self, n: int) -> int:
        flags_col = [1] * n
        flags_45 = [1] * (2*n - 1)
        flags_135 = [1] * (2*n - 1)
        count = 0
        def dfs(row):
            nonlocal count
            if row == n:
                count += 1
                return
            
            for col in range(n):
                if flags_col[col] and flags_45[row + col] and flags_135[row - col + n - 1]:
                    flags_col[col] = flags_45[row + col] = flags_135[row - col + n - 1] = 0
                    dfs(row + 1)
                    flags_col[col] = flags_45[row + col] = flags_135[row - col + n - 1] = 1
        dfs(0)
        return count
