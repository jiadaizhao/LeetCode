import collections
class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        graph = collections.defaultdict(list)
        for u, v in dislikes:
            graph[u].append(v)
            graph[v].append(u)
        
        colors = {}
        def dfs(curr, col):
            colors[curr] = col
            for next in graph[curr]:
                if next not in colors:
                    if not dfs(next, col ^ 1):
                        return False
                elif colors[curr] == colors[next]:
                    return False
            return True
        
        return all(dfs(curr, 0) for curr in range(1, N + 1) if curr not in colors)
