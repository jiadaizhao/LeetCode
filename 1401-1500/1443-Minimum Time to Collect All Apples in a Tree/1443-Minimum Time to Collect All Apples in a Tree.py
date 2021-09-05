import collections
class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        graph = collections.defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        def dfs(curr, prev):
            result = 0
            for next in graph[curr]:
                if next != prev:
                    result += dfs(next, curr)
                    
            if (result > 0 or hasApple[curr]) and curr != 0:
                result += 2
            return result
        
        return dfs(0, -1)
