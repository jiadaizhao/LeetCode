import collections
import heapq
class Solution:
    def reachableNodes(self, edges, M, N):
        """
        :type edges: List[List[int]]
        :type M: int
        :type N: int
        :rtype: int
        """
        graph = collections.defaultdict(dict)
        for i, j , n in edges:
            graph[i][j] = graph[j][i] = n + 1
            
        pq = [(-M, 0)]
        visited = {}
        while pq:
            moves, i = heapq.heappop(pq)
            if i not in visited:
                visited[i] = -moves
                for j in graph[i]:
                    if j not in visited:                        
                        nextMoves = -moves - graph[i][j]
                        if nextMoves >= 0:
                            heapq.heappush(pq, (-nextMoves, j))
                        
        count = len(visited)
        for i, j , n in edges:
            count += min(graph[i][j] - 1, visited.get(i, 0) + visited.get(j, 0))
        return count;
