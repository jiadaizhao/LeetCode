class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        graph = [[0] * n for _ in range(n)]
        degree = [0] * n
        for a, b in roads:
            graph[a][b] = graph[b][a] = 1
            degree[a] += 1
            degree[b] += 1
        maxRank = 0
        for i in range(n):
            for j in range(i + 1, n):
                maxRank = max(maxRank, degree[i] + degree[j] - (1 if graph[i][j] else 0))
        return maxRank
