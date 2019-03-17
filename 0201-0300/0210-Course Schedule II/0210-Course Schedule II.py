import collections
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = collections.defaultdict(list)
        for c1, c2 in prerequisites:
            graph[c2].append(c1)
            
        degrees = [0] * numCourses
        for k, v in graph.items():
            for c in v:
                degrees[c] += 1
                
        Q = collections.deque([c for c in range(numCourses) if degrees[c] == 0])
        result = []
        while Q:
            c = Q.popleft()
            result.append(c)
            for n in graph[c]:
                degrees[n] -= 1
                if degrees[n] == 0:
                    Q.append(n)
        return result if len(result) == numCourses else []
