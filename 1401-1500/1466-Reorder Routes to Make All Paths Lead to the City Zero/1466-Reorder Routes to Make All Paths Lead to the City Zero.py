import collections
class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(-u)
        def dfs(curr, prev):
            result = 0
            for next in graph[curr]:
                if prev != abs(next):
                    if next > 0:
                        result += 1
                    result += dfs(abs(next), curr)
            return result
        return dfs(0, -1)
