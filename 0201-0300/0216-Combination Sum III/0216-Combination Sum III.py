class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        if n < 0 or n > 45 or k <= 0:
            return []
        result = []
        path = []
        def dfs(start, s):
            if len(path) == k:
                if s == n:
                    result.append(path[:])
                return
            for i in range(start, 10):
                if s + i > n:
                    break
                path.append(i)
                dfs(i + 1, s + i)
                path.pop()
        
        dfs(1, 0)
        return result
