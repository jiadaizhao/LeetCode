class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result = []
        table = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        def dfs(start, path):
            if start == len(digits):
                result.append(path)
                return
            
            for c in table[int(digits[start])]:
                dfs(start + 1, path + c)
        if digits:
            dfs(0, '')
        return result
