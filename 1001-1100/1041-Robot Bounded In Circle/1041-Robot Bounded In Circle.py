class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x = y = dir = 0
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        for c in instructions:
            if c == 'L':
                dir = (dir - 1) % 4
            elif c == 'R':
                dir = (dir + 1) % 4
            else:
                x += dx[dir]
                y += dy[dir]

        return (x == 0 and y == 0) or dir != 0
