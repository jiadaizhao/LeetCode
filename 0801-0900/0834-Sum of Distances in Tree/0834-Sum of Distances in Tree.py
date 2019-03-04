class Solution:
    def sumOfDistancesInTree(self, N, edges):
        """
        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        sums = [0] * N
        counts = [1] * N
        def dfs1(curr, prev, graph, sums, counts):
            for next in graph[curr]:
                if next != prev:
                    dfs1(next, curr, graph, sums, counts)
                    sums[curr] += sums[next] + counts[next]
                    counts[curr] += counts[next]
                    
        def dfs2(curr, prev, graph, sums, counts):
            for next in graph[curr]:
                if next != prev:
                    sums[next] = sums[curr] - counts[next] + len(graph) - counts[next]               
                    dfs2(next, curr, graph, sums, counts)
                    
        dfs1(0, -1, graph, sums, counts)
        dfs2(0, -1, graph, sums, counts)
        return sums
