import collections
class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
        
        visited = [0] * n
        def dfs(curr):
            if visited[curr] == 1:
                return True
            elif visited[curr] == 2:
                return False
            elif len(graph[curr]) == 0:
                return curr == destination
            else:
                visited[curr] = 2
                for neighbor in graph[curr]:
                    if not dfs(neighbor):
                        return False
                visited[curr] = 1
                return True
        return dfs(source)
