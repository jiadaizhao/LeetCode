import collections
class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        graph = collections.defaultdict(list)
        for i in range(1, len(parent)):
            graph[parent[i]].append(i)
                
        def dfs(root):
            total = value[root]
            count = 1
            for child in graph[root]:
                s, c = dfs(child)
                total += s
                count += c
            return total, count if total != 0 else 0
        return dfs(0)[1]
