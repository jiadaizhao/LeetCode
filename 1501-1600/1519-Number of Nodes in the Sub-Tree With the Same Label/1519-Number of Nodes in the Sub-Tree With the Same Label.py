import collections
class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        graph = collections.defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        result = [0] * n    
        def dfs(curr, prev):
            table = collections.Counter([labels[curr]])
            for next in graph[curr]:
                if next != prev:
                    table += dfs(next, curr)
            result[curr] = table[labels[curr]]
            return table
        dfs(0, -1)
        return result
