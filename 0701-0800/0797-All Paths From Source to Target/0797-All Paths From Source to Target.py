class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        N = len(graph)
        result = []
        path = [0]
        def dfs(curr):
            if curr == N - 1:
                result.append(path[:])
                return
            
            for next in graph[curr]:
                path.append(next)
                dfs(next)
                path.pop()
        dfs(0)
        return result
