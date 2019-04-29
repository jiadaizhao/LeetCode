class Solution:
    def soupServings(self, N: int) -> float:
        if N >= 5000:
            return 1
        table = {}
        def dfs(a, b):
            if a <= 0 and b <= 0:
                return 0.5
            if a <= 0:
                return 1
            if b <= 0:
                return 0
            if (a, b) not in table:
                table[(a, b)] = 0.25*(dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3))
            return table[(a, b)]
        return dfs((N + 24)//25, (N + 24)//25)
