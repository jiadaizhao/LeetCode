import collections
import heapq
class Solution:
    def reachableNodes(self, edges: List[List[int]], M: int, N: int) -> int:
        graph = collections.defaultdict(dict)
        for i, j , n in edges:
            graph[i][j] = graph[j][i] = n
        
        pq = [(-M, 0)]
        visited = {}
        while pq:
            moves, i = heapq.heappop(pq)
            if i not in visited:
                moves = -moves
                visited[i] = moves
                for j in graph[i]:
                    if j not in visited:
                        nextMoves = moves - graph[i][j] - 1
                        if nextMoves>= 0:
                            heapq.heappush(pq, (-nextMoves, j))
        total = len(visited)
        for i, j, n in edges:
            total += min(graph[i][j], visited.get(i, 0) + visited.get(j, 0))
        return total
