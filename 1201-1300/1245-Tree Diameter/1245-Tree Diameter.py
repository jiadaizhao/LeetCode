import collections
class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        if not edges:
            return 0
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            
        maxLen = 0    
        def dfs(curr, prev):            
            maxLen1 = maxLen2 = 0
            for next in graph[curr]:
                if next != prev:
                    nextLen = dfs(next, curr)
                    if nextLen > maxLen1:
                        maxLen2 = maxLen1
                        maxLen1 = nextLen                        
                    elif nextLen > maxLen2:
                        maxLen2 = nextLen
            nonlocal maxLen
            maxLen = max(maxLen, maxLen1 + maxLen2)
            return 1 + maxLen1
        dfs(0, -1)
        return maxLen
