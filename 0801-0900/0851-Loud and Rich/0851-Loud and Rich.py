class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        graph = [[] for _ in range(len(quiet))]
        for u, v in richer:
            graph[v].append(u)
            
        result = [-1] * len(quiet)
        def dfs(curr):
            result[curr] = curr
            for next in graph[curr]:
                if result[next] == -1:
                    dfs(next)
                if quiet[result[next]] < quiet[result[curr]]:
                    result[curr] = result[next]
        
        for i in range(len(quiet)):
            if result[i] == -1:
                dfs(i)
        return result
