import collections
class Solution:
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        graph = collections.defaultdict(list)
        for u, v in dislikes:
            graph[u].append(v)
            graph[v].append(u)
        
        colors = {}
        def dfs(curr, col):
            colors[curr] = col
            for nex in graph[curr]:
                if nex not in colors:
                    if not dfs(nex, col ^ 1):
                        return False
                elif colors[curr] == colors[nex]:
                    return False
            return True
        
        return all(dfs(curr, 0) for curr in range(1, N + 1) if curr not in colors)
