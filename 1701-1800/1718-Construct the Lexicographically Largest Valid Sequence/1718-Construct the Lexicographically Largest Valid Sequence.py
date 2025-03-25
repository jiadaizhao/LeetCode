class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        result = [0] * (n * 2 - 1)
        visited = [False] * (n + 1)
        def dfs(start):
            if start == len(result):
                return True
            if result[start]:
                return dfs(start + 1)
            
            for i in range(n, 0, -1):
                if not visited[i]:
                    visited[i] = True
                    result[start] = i
                    if i == 1:
                        if dfs(start + 1):
                            return True
                    elif start + i < len(result) and result[start + i] == 0:
                        result[start + i] = i
                        if dfs(start + 1):
                            return True
                        result[start + i] = 0
                    visited[i] = False
                    result[start] = 0
            return False
        dfs(0)
        return result
