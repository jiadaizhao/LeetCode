class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    count = 0
                    for dr, dc in (-1, 0), (1, 0), (0, -1), (0, 1):
                        nr = i + dr
                        nc = j + dc
                        while 0 <= nr < 8 and 0 <= nc < 8 and board[nr][nc] != 'B':
                            if board[nr][nc] == 'p':
                                count += 1
                                break
                            nr += dr
                            nc += dc
                    return count
        return 0
