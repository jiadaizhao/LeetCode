import collections
class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        Q = collections.deque()
        total = 0
        for i in range(len(A)):
            for j in range(len(A[0])):
                if A[i][j] == 1:
                    if i == 0 or i == len(A) - 1 or j == 0 or j == len(A[0]) - 1:
                        A[i][j] = 0
                        Q.append((i, j))
                    else:
                        total += 1
                
        while Q:
            row, col = Q.popleft()
            for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                if 0 <= nr < len(A) and 0 <= nc < len(A[0]) and A[nr][nc] == 1:
                    A[nr][nc] = 0
                    Q.append((nr, nc))
                    total -= 1
                    
        return total
