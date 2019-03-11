class Solution:
    def partition(self, s: str) -> List[List[str]]:
        palindrome = [[False]*len(s) for _ in range(len(s))]
        for j in range(len(s)):
            for i in range(j + 1):
                if s[i] == s[j] and (j - i < 2 or palindrome[i+1][j-1]):
                    palindrome[i][j] = True
        result = []
        path = []
        def dfs(start):
            if start == len(s):
                result.append(path[:])
                return
            
            for i in range(start, len(s)):
                if palindrome[start][i]:
                    path.append(s[start:i+1])
                    dfs(i + 1)
                    path.pop()
        dfs(0)
        return result
