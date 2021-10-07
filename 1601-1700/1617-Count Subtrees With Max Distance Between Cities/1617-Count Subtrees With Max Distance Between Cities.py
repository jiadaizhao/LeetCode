import collections
class Solution:
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)
        
        def treeDiameter(cities):
            maxLen = 0
            visited = 0
            def dfs(curr, prev):            
                maxLen1 = maxLen2 = 0
                nonlocal visited
                visited += 1
                for next in graph[curr]:
                    if next != prev and next in cities:
                        nextLen = dfs(next, curr)
                        if nextLen > maxLen1:
                            maxLen2 = maxLen1
                            maxLen1 = nextLen                        
                        elif nextLen > maxLen2:
                            maxLen2 = nextLen
                nonlocal maxLen
                maxLen = max(maxLen, maxLen1 + maxLen2)
                return 1 + maxLen1
            start = cities.pop()
            cities.add(start)
            dfs(start, -1)
            return maxLen if visited == len(cities) else 0
        
        def maxDistance(state):
            cities = set()
            for i in range(n):
                if state & (1 << i):
                    cities.add(i)
            return treeDiameter(cities)
        
        result = [0] * (n - 1)
        for state in range(1, 1 << n):
            d = maxDistance(state)
            if d != 0:
                result[d - 1] += 1
        return result
