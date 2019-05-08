class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obs = set(map(tuple, obstacles))
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        maxDist = di = x = y = 0
        for command in commands:
            if command == -2:
                di = (di - 1) % 4
            elif command == -1:
                di = (di + 1) % 4
            else:
                for _ in range(command):
                    nx = x + dx[di]
                    ny = y + dy[di]
                    if (nx, ny) not in obs:
                        x = nx
                        y = ny
                        maxDist = max(maxDist, x*x + y*y)
                    else:
                        break

        return maxDist
