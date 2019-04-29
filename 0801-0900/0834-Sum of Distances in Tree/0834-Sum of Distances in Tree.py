import collections
class Solution:
    def sumOfDistancesInTree(self, N: int, edges: List[List[int]]) -> List[int]:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        count = [1] * N
        ans = [0] * N
        def dfs1(curr, prev):
            for next in graph[curr]:
                if next != prev:
                    dfs1(next, curr)
                    ans[curr] += ans[next] + count[next]
                    count[curr] += count[next]
                    
        def dfs2(curr, prev):
            for next in graph[curr]:
                if next != prev:
                    ans[next] = ans[curr] - count[next] + N - count[next]
                    dfs2(next, curr)
        dfs1(0, -1)
        dfs2(0, -1)
        return ans
