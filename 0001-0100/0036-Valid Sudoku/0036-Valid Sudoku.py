class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        usedRows = [[False]*9 for _ in range(9)]
        usedCols = [[False]*9 for _ in range(9)]
        usedBlocks = [[False]*9 for _ in range(9)]
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if c != '.':
                    index = ord(c) - ord('0') - 1
                    k = i // 3 * 3 + j // 3
                    if usedRows[i][index] or usedCols[j][index] or usedBlocks[k][index]:
                        return False
                    usedRows[i][index] = usedCols[j][index] = usedBlocks[k][index] = True
        return True
