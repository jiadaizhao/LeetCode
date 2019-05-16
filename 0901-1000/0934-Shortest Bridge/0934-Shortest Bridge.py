import collections
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        Q = collections.deque()
        def dfs(row, col):
            A[row][col] = 2
            Q.append((row, col))
            for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                if 0 <= nr < len(A) and 0 <= nc < len(A[nr]) and A[nr][nc] == 1: 
                    dfs(nr, nc)
        found = False            
        for i in range(len(A)):
            for j in range(len(A[i])):
                if A[i][j] == 1:
                    dfs(i, j)
                    found = True
                    break
            if found:
                break

        count = 0

        while Q:
            qs = len(Q)            
            for i in range(qs):
                row, col = Q.popleft()
                for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                    if 0 <= nr < len(A) and 0 <= nc < len(A[nr]): 
                        if A[nr][nc] == 1:
                            return count
                        elif A[nr][nc] == 0:
                            A[nr][nc] = 2
                            Q.append((nr, nc))
            count += 1
        return -1
