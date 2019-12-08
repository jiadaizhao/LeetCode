class Solution:
    def minimumCost(self, N: int, connections: List[List[int]]) -> int:
        parent = [i for i in range(1 + N)]
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        connections.sort(key=lambda x: x[2])
        total = num = 0
        for city1, city2, cost in connections:
            p1 = findParent(city1)
            p2 = findParent(city2)
            if p1 != p2:
                parent[p2] = p1
                total += cost
                num += 1
                if num == N - 1:
                    return total
        
        return -1
