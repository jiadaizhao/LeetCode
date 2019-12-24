class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        path = []
        def dfs(start, n, k):
            if len(path) == k:
                result.append(path[:])
                return

            for i in range(start, n + len(path) - k + 2):
                path.append(i)
                dfs(i + 1, n, k)
                path.pop()

        dfs(1, n, k)
        return result
