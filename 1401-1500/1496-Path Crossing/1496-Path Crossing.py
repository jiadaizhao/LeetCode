class Solution:
    def isPathCrossing(self, path: str) -> bool:
        table = set([(0, 0)])
        x = y = 0
        for d in path:
            if d == 'N':
                y += 1
            elif d == 'S':
                y -= 1
            elif d == 'E':
                x += 1
            elif d == 'W':
                x -= 1
            if (x, y) in table:
                return True
            table.add((x, y))
        return False
