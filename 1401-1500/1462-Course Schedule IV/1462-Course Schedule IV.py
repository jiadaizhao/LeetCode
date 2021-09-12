class Solution1:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        r = [[False] * numCourses for _ in range(numCourses)]
        for u, v in prerequisites:
            r[u][v] = True
        for k in range(numCourses):
            for i in range(numCourses):
                for j in range(numCourses):
                    r[i][j] = r[i][j] or (r[i][k] and r[k][j])

        return [r[u][v] for u, v in queries]

import collections
class Solution2:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = collections.defaultdict(list)
        for u, v in prerequisites:
            graph[u].append(v)
        table = {}
        def dfs(u):
            if u in table:
                return table[u]
            table[u] = set()
            for v in graph[u]:
                table[u].add(v)
                table[u].update(dfs(v))
            return table[u]
        return [v in dfs(u) for u, v in queries]
