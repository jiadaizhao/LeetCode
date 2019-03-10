class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if len(board) == 0 or len(board[0]) == 0:
            return word == ''
        def dfs(start, row, col):
            if start == len(word):
                return True
            if row < 0 or row >= len(board) or col < 0 or col >= len(board[0]) or \
                board[row][col] == '#' or board[row][col] != word[start]:
                return False
            
            c = board[row][col]
            board[row][col] = '#'
            result = dfs(start+1, row-1, col) or dfs(start+1, row+1, col) or dfs(start+1, row, col-1) or dfs(start+1, row, col+1)
            board[row][col] = c
            return result
        
        return any(dfs(0, row, col) for row in range(len(board)) for col in range(len(board[0])))
