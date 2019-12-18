class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        rows = [0] * 3
        cols = [0] * 3
        diag = antidiag = 0
        for i, (r, c) in enumerate(moves):
            val = 1 if (i & 1) else -1
            rows[r] += val
            cols[c] += val
            if r == c:
                diag += val
            if r + c == 2:
                antidiag += val
            if abs(rows[r]) == 3 or abs(cols[c]) == 3 or abs(diag) == 3 or abs(antidiag) == 3:
                return 'B' if (i & 1) else 'A'
        return 'Draw' if len(moves) == 9 else 'Pending'
