class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        result = []
        row = col = 0
        for c in target:
            tr = (ord(c) - ord('a')) // 5
            tc = (ord(c) - ord('a')) % 5           
            if col > tc:
                result.append('L' * (col - tc))
            if row < tr:
                result.append('D' * (tr - row))
            if row > tr:
                result.append('U' * (row - tr))
            if col < tc:
                result.append('R' * (tc - col))
            result.append('!')
            row, col = tr, tc

        return ''.join(result)
