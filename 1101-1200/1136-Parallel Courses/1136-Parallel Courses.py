import collections
class Solution:
    def minimumSemesters(self, N: int, relations: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        degrees = [0] * (N + 1)
        for x, y in relations:
            graph[x].append(y)
            degrees[y] += 1
            
        Q = collections.deque([i for i in range(1, N + 1) if degrees[i] == 0])
        course = semester = 0
        while Q:
            semester += 1
            for _ in range(len(Q)):
                curr = Q.popleft()
                course += 1
                for n in graph[curr]:
                    degrees[n] -= 1
                    if degrees[n] == 0:
                        Q.append(n)
        return semester if course == N else -1
