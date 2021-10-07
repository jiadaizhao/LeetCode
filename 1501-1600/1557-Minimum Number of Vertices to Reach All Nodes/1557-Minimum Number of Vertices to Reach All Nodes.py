class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        degree = [0] * n
        for u, v in edges:
            degree[v] = 1
        return [i for i, d in enumerate(degree) if d == 0]
