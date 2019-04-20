class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        first, second = 'XO'
        countX = sum(row.count(first) for row in board)
        countO = sum(row.count(second) for row in board)
        if countO > countX or countX - countO > 1:
            return False
        def win(player):
            for i in range(3):
                if all(board[i][j] == player for j in range(3)):
                    return True
                if all(board[j][i] == player for j in range(3)):
                    return True
            return (player == board[1][1] == board[0][0] == board[2][2] or
                    player == board[1][1] == board[0][2] == board[2][0]) 
            
        if win(first) and countX != countO + 1:
            return False
        if win(second) and countX != countO:
            return False
        return True

class Solution2:
    def validTicTacToe(self, board: List[str]) -> bool:
        countX = countO = diag = antidiag = 0
        rows = [0]*3
        cols = [0]*3
        winX = winO = False
        for i in range(3):
            for j in range(3):
                if board[i][j] == 'X':
                    countX += 1
                    rows[i] += 1
                    cols[j] += 1
                    if i == j:
                        diag += 1
                    if i + j == 2:
                        antidiag += 1
                elif board[i][j] == 'O':
                    countO += 1
                    rows[i] -= 1
                    cols[j] -= 1
                    if i == j:
                        diag -= 1
                    if i + j == 2:
                        antidiag -= 1
        if countO > countX or countX - countO > 1:
            return False
        
        if any(rows[i] == 3 for i in range(3)) or any(cols[j] == 3 for j in range(3)) or diag == 3 or antidiag == 3:
            winX = True
            
        if any(rows[i] == -3 for i in range(3)) or any(cols[j] == -3 for j in range(3)) or diag == -3 or antidiag == -3:
            winO = True
        
        if winX and countX != countO + 1:
            return False
        if winO and countX != countO:
            return False
        return True
