import heapq
class Solution:
    def maximumMinimumPath(self, A: List[List[int]]) -> int:
        R, C = len(A), len(A[0])
        pq = [(-A[0][0], 0, 0)]
        score = A[0][0]
        A[0][0] = -1
        while pq:
            v, r, c = heapq.heappop(pq)
            if r == R - 1 and c == C - 1:
                return -v
            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                if 0 <= nr < R and 0 <= nc < C and A[nr][nc] >= 0:
                    heapq.heappush(pq, (max(v, -A[nr][nc]), nr, nc))
                    A[nr][nc] = -1
