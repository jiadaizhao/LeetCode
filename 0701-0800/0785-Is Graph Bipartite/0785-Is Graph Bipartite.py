class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        visited = [0] * len(graph)
        def dfs(curr, prev):
            visited[curr] = 1 if prev == -1 else 3 - visited[prev]
            for next in graph[curr]:
                if visited[next] == 0 and not dfs(next, curr):
                    return False
                elif visited[next] == visited[curr]:
                    return False
            return True
        
        for i in range(len(graph)):
            if visited[i] == 0 and not dfs(i, -1):
                return False
        return True
