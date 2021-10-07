class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        friends = [0] * n
        for x, y in pairs:
            friends[x] = y
            friends[y] = x
        
        table = [dict() for _ in range(n)]
        for i in range(n):
            for j in range(n - 1):
                table[i][preferences[i][j]] = j
        
        count = 0
        for x in range(n):
            y = friends[x]
            for u in preferences[x]:
                v = friends[u]
                if table[x][u] < table[x][y] and table[u][x] < table[u][v]:
                    count += 1
                    break
        return count
