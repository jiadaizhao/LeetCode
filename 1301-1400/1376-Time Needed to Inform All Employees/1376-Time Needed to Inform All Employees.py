import collections
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        table = collections.defaultdict(list)
        for i, m in enumerate(manager):
            table[m].append(i)
            
        Q = collections.deque([(headID, 0)])
        mins = 0
        while Q:
            curr, time = Q.popleft()
            mins = max(mins, time)
            for e in table[curr]:
                Q.append((e, time + informTime[curr]))
        return mins
