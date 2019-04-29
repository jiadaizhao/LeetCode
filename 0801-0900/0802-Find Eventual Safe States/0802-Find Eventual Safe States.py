import collections
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        edges = [[] for _ in range(n)]
        degrees = [0] * n
        Q = collections.deque()
        for i in range(n):
            degrees[i] = len(graph[i])
            if degrees[i] == 0:
                Q.append(i)
            else:
                for j in graph[i]:
                    edges[j].append(i)
        safe = [False] * n
        while Q:
            u = Q.popleft()
            safe[u] = True
            for v in edges[u]:
                degrees[v] -= 1
                if degrees[v] == 0:
                    Q.append(v)
        return [i for i, s in enumerate(safe) if s]
