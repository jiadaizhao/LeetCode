import collections
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        probs = [0] * (n + 1)
        probs[1] = 1
        def dfs(curr, prev, t):
            if t == 0:
                return
            stay = True
            sz = len(graph[curr]) if curr == 1 else len(graph[curr]) - 1
            for next in graph[curr]:
                if next != prev:
                    stay = False
                    probs[next] += probs[curr] / sz
                    dfs(next, curr, t - 1)
            if not stay:
                probs[curr] = 0
            
        dfs(1, 0, t)
        return probs[target]
