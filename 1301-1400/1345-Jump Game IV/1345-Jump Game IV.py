import collections
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        table = collections.defaultdict(list)
        for i, a in enumerate(arr):
            table[a].append(i)
        visited = [False] * len(arr)
        Q = collections.deque([0])
        visited[0] = True
        step = 0
        while Q:
            for _ in range(len(Q)):
                curr = Q.popleft()
                if curr == len(arr) - 1:
                    return step
                if curr - 1 >= 0 and not visited[curr - 1]:
                    Q.append(curr - 1)
                    visited[curr - 1] = True
                if curr + 1 < len(arr) and not visited[curr + 1]:
                    Q.append(curr + 1)
                    visited[curr + 1] = True
                for next in table[arr[curr]]:
                    if not visited[next]:
                        Q.append(next)
                        visited[next] = True
                table[arr[curr]].clear()
            step += 1
        return step
