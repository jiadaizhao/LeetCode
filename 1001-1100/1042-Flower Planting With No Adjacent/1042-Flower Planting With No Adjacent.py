import collections
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        graph = collections.defaultdict(list)
        for x, y in paths:
            graph[x].append(y)
            graph[y].append(x)
            
        garden = [0] * N
        for i in range(N):
            used = [False] * 5
            for neighbor in graph[i + 1]:
                used[garden[neighbor - 1]] = True
            for color in range(1, 5):
                if not used[color]:
                    garden[i] = color
                    break
        
        return garden
