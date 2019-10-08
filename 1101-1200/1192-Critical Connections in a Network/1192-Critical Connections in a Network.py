import collections

class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph = collections.defaultdict(list)
        for a, b in connections:
            graph[a].append(b)
            graph[b].append(a)

        connections = set(map(tuple, map(sorted, connections)))
        rank = [-2] * n
        def dfs(curr, depth):
            if rank[curr] >= 0:
                return rank[curr]
            rank[curr] = depth
            minDepth = n
            for neighbor in graph[curr]:
                if rank[neighbor] == depth - 1:
                    continue
                nextDepth = dfs(neighbor, depth + 1)
                if nextDepth <= depth:
                    connections.discard(tuple(sorted((curr, neighbor))))
                minDepth = min(minDepth, nextDepth)
            rank[curr] = n
            return minDepth

        dfs(0, 0)
        return list(connections)
