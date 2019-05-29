import collections
class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:
        table = collections.Counter(A)
        nextNum = {x : {y for y in table if int((x + y) ** 0.5) ** 2 == x + y} for x in table}
        count = 0
        def dfs(x, num):
            if num == len(A):
                nonlocal count
                count += 1
                return
            table[x] -= 1
            for y in nextNum[x]:
                if table[y] > 0:
                    dfs(y, num + 1)
            table[x] += 1
            
        for x in table:
            dfs(x, 1)
        return count



from functools import lru_cache
import math
class Solution2:
    def numSquarefulPerms(self, A: List[int]) -> int:
        graph = [[] for _ in range(len(A))]
        for i in range(len(A)):
            for j in range(i):
                if int((A[i] + A[j]) ** 0.5) ** 2 == A[i] + A[j]:
                    graph[i].append(j)
                    graph[j].append(i)
                    
        @lru_cache(None)
        def dfs(node, visited):
            if visited == (1 << len(A)) - 1:
                return 1
            
            count = 0
            for nei in graph[node]:
                if (1 << nei) & visited == 0:
                    count += dfs(nei, visited | (1 << nei))
            return count
        
        total = sum(dfs(i, 1 << i) for i in range(len(A)))
        table = collections.Counter(A)
        for v in table.values():
            total //= math.factorial(v)
        return total
