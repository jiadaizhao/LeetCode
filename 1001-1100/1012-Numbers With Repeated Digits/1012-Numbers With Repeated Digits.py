class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        num = list(map(int, str(N + 1)))
        visited = set()
        total = 0
        def perm(m, n):
            result = 1
            curr = m
            while curr >= m - n + 1:
                result *= curr
                curr -= 1
            return result
        
        for i in range(1, len(num)):
            total += 9 * perm(9, i - 1)

        for i, d in enumerate(num):
            for j in range(0 if i > 0 else 1, d):
                if j not in visited:
                    total += perm(9 - i, len(num) - 1 - i)
            if d in visited:
                break
            visited.add(d)
        
        return N - total
