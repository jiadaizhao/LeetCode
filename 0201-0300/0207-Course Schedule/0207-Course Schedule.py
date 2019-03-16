import collections
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = collections.defaultdict(list)
        for c1, c2 in prerequisites:
            graph[c2].append(c1)
            
        degrees = [0] * numCourses
        for k, v in graph.items():
            for c in v:
                degrees[c] += 1
                
        Q = collections.deque([c for c in range(numCourses) if degrees[c] == 0])
        count = 0
        while Q:
            count += 1
            c = Q.popleft()
            for n in graph[c]:
                degrees[n] -= 1
                if degrees[n] == 0:
                    Q.append(n)
                    
        return count == numCourses
