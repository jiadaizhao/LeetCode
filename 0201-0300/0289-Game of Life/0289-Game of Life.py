class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        for i in range(len(board)):
            for j in range(len(board[0])):
                count = 0
                for r, c in ((i-1, j-1), (i-1, j), (i-1, j+1), (i, j-1), (i, j+1), (i+1, j-1), (i+1, j), (i+1, j+1)):
                    if 0 <= r < len(board) and 0 <= c < len(board[0]) and (board[r][c]&1):
                        count += 1
                        
                if board[i][j]&1:
                    if count == 2 or count == 3:
                        board[i][j] |= 2
                elif count == 3:
                    board[i][j] |= 2
                    
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] >>= 1
