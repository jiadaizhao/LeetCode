import collections
class Solution:
    def minMutation(self, start: 'str', end: 'str', bank: 'List[str]') -> 'int':
        bankSet = set(bank)
        Q = collections.deque()
        visited = set()
        Q.append(start)
        visited.add(start)
        step = 0
        while Q:
            step += 1
            qs = len(Q)
            for i in range(qs):
                s = Q.popleft()
                for j in range(len(s)):
                    for c in 'ACGT':
                        nextS = s[:j] + c + s[j+1:]
                        if nextS not in bankSet:
                            continue
                        if nextS == end:
                            return step
                        if nextS not in visited:
                            Q.append(nextS)
                            visited.add(nextS)
        return -1
