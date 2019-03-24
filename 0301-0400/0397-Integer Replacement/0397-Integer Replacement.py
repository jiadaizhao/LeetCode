class Solution:
    def integerReplacement(self, n: 'int') -> 'int':
        table = {1:0}
        def dfs(n):
            if n in table:
                return table[n]
            if n & 1:
                result = 1 + min(dfs(n + 1), dfs(n - 1))
            else:
                result = 1 + dfs(n // 2)
            table[n] = result
            return result
        return dfs(n)
