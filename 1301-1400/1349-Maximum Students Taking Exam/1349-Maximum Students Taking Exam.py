class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        m, n = len(seats), len(seats[0])
        mask = [0] * m
        for i in range(m):
            for j in range(n):
                if seats[i][j] == '.':
                    mask[i] |= (1 << j)

        dp = [0] * (1 << n)
        for i in range(m):
            temp = [0] * (1 << n)
            for j in range(1 << n):
                if (j & mask[i]) == j and not (j & (j >> 1)):
                    for k in range(1 << n):
                        if not (j & (k >> 1)) and not ((j >> 1) & k):
                            temp[j] = max(temp[j], dp[k] + bin(j).count('1'))
            dp = temp
        return max(dp)


# https://leetcode.com/problems/maximum-students-taking-exam/discuss/503790/Python-Hungarian-Time-O(m2*n2)-Space-O(m*n)-beat-100
# https://www.renfei.org/blog/bipartite-matching.html
class Solution2:
    def maxStudents(self, seats: List[List[str]]) -> int:
        R, C = len(seats), len(seats[0])
        
        matching = [[-1] * C for _ in range(R)]
        
        def dfs(node, seen):
            r, c = node
            for nr, nc in [[r-1,c-1], [r,c-1],[r,c+1],[r-1,c+1],[r+1,c-1],[r+1,c+1]]: # assume a virtual edge connecting students who can spy
                if 0 <= nr < R and 0 <= nc < C and seen[nr][nc] == False and seats[nr][nc] == '.':
                    seen[nr][nc] = True
                    if matching[nr][nc] == -1 or dfs(matching[nr][nc], seen):
                        matching[nr][nc] = (r,c)
                        return True
            return False
        
        def Hungarian():
            res = 0
            for c in range(0,C,2):
                for r in range(R):
                    if seats[r][c] == '.':
                        seen = [[False] * C for _ in range(R)]
                        if dfs((r,c), seen):
                            res += 1
            return res
        
        res = Hungarian()
                
        count = 0
        for r in range(R):
            for c in range(C):
                if seats[r][c] == '.':
                    count += 1
        return count - res                       
