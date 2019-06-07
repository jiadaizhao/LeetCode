import collections
class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        def bfs(source, target):
            block = set((row, col) for row, col in blocked)
            limit = len(blocked) * (len(blocked) - 1) // 2
            Q = collections.deque([source])
            area = 0
            block.add((source[0], source[1]))
            while Q:
                row, col = Q.popleft()
                area += 1
                if area > limit:
                    return True
                for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                    if 0 <= nr < 10**6 and 0 <= nc < 10**6 and (nr, nc) not in block:
                        if nr == target[0] and nc == target[1]:
                            return True
                        Q.append([nr, nc])
                        block.add((nr, nc))

            return False

        return bfs(source, target) and bfs(target, source)           
