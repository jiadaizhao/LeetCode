class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        result = ['0'] * n
        visited = set([''.join(result)])
        for i in range(k ** n):
            prev = result[len(result) - n + 1:]
            for j in range(k - 1, -1, -1):
                curr = ''.join(prev) + str(j)
                if curr not in visited:
                    visited.add(curr)
                    result.append(str(j))
                    break
        return ''.join(result)
