import collections
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        Q = collections.deque()
        for i in range(len(board)):
            for j in range(len(board[i])):
                if (i in (0, len(board) - 1) or j in (0, len(board[i]) - 1)) and board[i][j] == 'O':
                    Q.append((i, j))
                    board[i][j] = '#'
                    
        while Q:
            row, col = Q.popleft()
            for nr, nc in ((row-1, col), (row+1, col), (row, col-1), (row, col+1)):
                if 0 <= nr < len(board) and 0 <= nc < len(board[0]) and board[nr][nc] == 'O':
                    Q.append((nr, nc))
                    board[nr][nc] = '#'
                    
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '#':
                    board[i][j] = 'O'
