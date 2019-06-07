class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])
        maxMove = c - a - 2
        if b - a == 1 and c - b == 1:
            minMove = 0
        elif b - a <= 2 or c - b <= 2:
            minMove = 1
        else:
            minMove = 2
        return [minMove, maxMove]
