import collections
class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        rg = [[] for _ in range(n)]
        bg = [[] for _ in range(n)]
        for i, j in red_edges:
            rg[i].append(j)
        for i, j in blue_edges:
            bg[i].append(j)
        
        # True if last edge is red
        Q = collections.deque([(0, True), (0, False)])
        red = [-1] * n
        red[0] = 0
        blue = [-1] * n
        blue[0] = 0
        step = 0
        while Q:
            step += 1
            for _ in range(len(Q)):
                i, lastRed = Q.popleft()
                if lastRed:
                    for j in bg[i]:
                        if blue[j] == -1:
                            blue[j] = step
                            Q.append((j, False))
                else:
                    for j in rg[i]:
                        if red[j] == -1:
                            red[j] = step
                            Q.append((j, True))
        
        answer = [0] * n
        for i in range(1, n):
            if red[i] != -1:
                answer[i] = min(red[i], blue[i]) if blue[i] != -1 else red[i]
            else:
                answer[i] = blue[i]
        
        return answer
