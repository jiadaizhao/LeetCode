import heapq
class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 'S':
                    player = (i, j)
                elif grid[i][j] == 'B':
                    box = (i, j)
                elif grid[i][j] == 'T':
                    target = (i, j)
        
        def distance(box):
            return abs(box[0] - target[0]) + abs(box[1] - target[1])
        
        def illegalPos(pos):
            return (pos[0] < 0 or pos[0] >= len(grid) or pos[1] < 0 or
                    pos[1] >= len(grid[0]) or grid[pos[0]][pos[1]] == '#')

        pq = [(distance(box), 0, player, box)]
        visited = set([(player, box)])
        while pq:
            d, move, player, box = heapq.heappop(pq)
            if box == target:
                return move
            for dr, dc in (-1, 0), (1, 0), (0, -1), (0, 1):
                np = (player[0] + dr, player[1] + dc)
                if illegalPos(np):
                    continue
                    
                if np == box:
                    nb = (box[0] + dr, box[1] + dc)
                    if illegalPos(nb) or (np, nb) in visited:
                        continue
                    visited.add((np, nb))
                    heapq.heappush(pq, (distance(nb) + move + 1, move + 1, np, nb))
                else:
                    if (np, box) in visited:
                        continue
                    visited.add((np, box))
                    heapq.heappush(pq, (d, move, np, box))
                    
        return -1
