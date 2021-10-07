class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        visited = set()
        def dfs(curr):
            if curr == len(s):
                return 0
            count = 0
            for i in range(curr, len(s)):
                ss = s[curr : i + 1]
                if ss in visited:
                    continue
                visited.add(ss)
                count = max(count, 1 + dfs(i + 1))
                visited.remove(ss)
            return count
        return dfs(0)
