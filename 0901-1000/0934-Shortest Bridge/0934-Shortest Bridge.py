import collections
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:        
        Q = collections.deque()
        def dfs(r, c):
            A[r][c] = 2
            Q.append((r, c))
            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                if 0 <= nr < len(A) and 0 <= nc < len(A[0]) and A[nr][nc] == 1: 
                    dfs(nr, nc)
                    
        def findFirstIsland():
            for i in range(len(A)):
                for j in range(len(A[i])):
                    if A[i][j] == 1:
                        dfs(i, j)
                        return
        findFirstIsland()
        count = 0

        while Q:      
            for i in range(len(Q)):
                r, c = Q.popleft()
                for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                    if 0 <= nr < len(A) and 0 <= nc < len(A[nr]): 
                        if A[nr][nc] == 1:
                            return count
                        elif A[nr][nc] == 0:
                            A[nr][nc] = 2
                            Q.append((nr, nc))
            count += 1
        return -1
