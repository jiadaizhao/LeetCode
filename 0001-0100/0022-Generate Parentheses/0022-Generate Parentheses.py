class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        def dfs(path, left, right):
            if left == 0 and right == 0:
                result.append(path)
                return
            if left > 0:
                dfs(path + '(', left - 1, right)
            
            if left < right:
                dfs(path + ')', left, right - 1)
        dfs('', n, n)
        return result
