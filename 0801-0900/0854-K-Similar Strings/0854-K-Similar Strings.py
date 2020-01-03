import collections
class Solution:
    def kSimilarity(self, A: str, B: str) -> int:
        if A == B:
            return 0
        Q = collections.deque([A])
        visited = set([A])
        count = 0
        while Q:
            count += 1
            for _ in range(len(Q)):
                s = Q.popleft()
                i = 0
                while s[i] == B[i]:
                    i += 1
                for j in range(i + 1, len(B)):
                    if s[i] == B[j] and s[j] != B[j]:
                        C = s[:i] + s[j] + s[i+1: j] + s[i] + s[j+1:]
                        if C == B:
                            return count
                        if C not in visited:
                            Q.append(C)
                            visited.add(C)
        return -1
