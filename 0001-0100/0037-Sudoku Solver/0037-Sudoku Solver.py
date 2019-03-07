class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        usedRows = [[False]*9 for _ in range(9)]
        usedCols = [[False]*9 for _ in range(9)]
        usedBlocks = [[False]*9 for _ in range(9)]
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if c != '.':
                    index = ord(c) - ord('0') - 1
                    k = i // 3 * 3 + j // 3
                    usedRows[i][index] = usedCols[j][index] = usedBlocks[k][index] = True
        def dfs():
            for i, row in enumerate(board):
                for j, c in enumerate(row):
                    if c == '.':
                        for v in '123456789':
                            index = ord(v) - ord('0') - 1
                            k = i // 3 * 3 + j // 3
                            if not usedRows[i][index] and not usedCols[j][index] and not usedBlocks[k][index]:
                                board[i][j] = v
                                usedRows[i][index] = usedCols[j][index] = usedBlocks[k][index] = True
                                if dfs():
                                    return True
                                usedRows[i][index] = usedCols[j][index] = usedBlocks[k][index] = False
                                board[i][j] = '.'
                        return False
            return True
        dfs()
