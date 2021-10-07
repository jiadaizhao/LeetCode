class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        visited = set()
        result = s
        def dfs(s):
            if s in visited:
                return
            nonlocal result
            result = min(result, s)
            visited.add(s)
                        
            sl = list(s)
            for i in range(1, len(s), 2):
                sl[i] = str((int(sl[i]) + a) % 10)
            dfs(''.join(sl))
            dfs(s[-b:] + s[:-b])
        dfs(s)
        return result
