class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        N = len(board)
        rowSum = colSum = rowSwap = colSwap = 0
        for i in range(N):
            for j in range(N):
                if board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]:
                    return -1
                
        for i in range(N):
            rowSum += board[0][i]
            colSum += board[i][0]
            rowSwap += (board[i][0] == i % 2)
            colSwap += (board[0][i] == i % 2)
            
        if ((rowSum != N // 2 + N % 2 and rowSum != N // 2) or
            (colSum != N // 2 + N % 2 and colSum != N // 2)):
            return -1
        if N % 2:
            if colSwap % 2:
                colSwap = N - colSwap
            if rowSwap % 2:
                rowSwap = N - rowSwap
        else:
            colSwap = min(N - colSwap, colSwap)
            rowSwap = min(N - rowSwap, rowSwap)
        return (colSwap + rowSwap) // 2
