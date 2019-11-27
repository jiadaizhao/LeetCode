import collections
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:        
        row, col = click
        if board[row][col] == 'M':
            board[row][col] = 'X'
            return board
        m, n = len(board), len(board[0])
        Q = collections.deque([(row, col)])
        board[row][col] = 'B'
        while Q:
            r, c = Q.popleft()
            count = 0
            for nr, nc in (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1):
                if 0 <= nr < m and 0 <= nc < n and board[nr][nc] == 'M':
                    count += 1
                    
            if count > 0:
                board[r][c] = str(count)
            else:
                for nr, nc in (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1):
                    if 0 <= nr < m and 0 <= nc < n and board[nr][nc] == 'E':
                        Q.append((nr, nc))
                        board[nr][nc] = 'B'
        return board
