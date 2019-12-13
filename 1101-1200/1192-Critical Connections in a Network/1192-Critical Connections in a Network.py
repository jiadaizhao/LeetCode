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
            minDepth = depth
            for neighbor in graph[curr]:
                if rank[neighbor] == depth - 1:
                    continue
                nextDepth = dfs(neighbor, depth + 1)
                if nextDepth <= depth:
                    connections.discard(tuple(sorted((curr, neighbor))))
                minDepth = min(minDepth, nextDepth)
            return minDepth

        dfs(0, 0)
        return list(connections)


class Solution2:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph = collections.defaultdict(list)
        for a, b in connections:
            graph[a].append(b)
            graph[b].append(a)
            
        low = [-1] * n
        ids = [-1] * n
        time = 0
        result = []
        def dfs(curr, prev):
            nonlocal time
            time += 1
            low[curr] = ids[curr] = time
            for neighbor in graph[curr]:
                if neighbor == prev:
                    continue
                if low[neighbor] == -1:
                    dfs(neighbor, curr)
                    low[curr] = min(low[curr], low[neighbor])
                    if ids[curr] < low[neighbor]:
                        result.append([curr, neighbor])
                else:
                    low[curr] = min(low[curr], ids[neighbor])
                    
        dfs(0, -1)
        return result
