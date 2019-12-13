class Solution:
    def expand(self, S: str) -> List[str]:
        result = []
        def dfs(start, path):
            if start == len(S):
                result.append(path)
                return
            
            if S[start] == '{':
                index = S.find('}', start + 1)
                for c in sorted(S[start + 1:index].split(',')):
                    dfs(index + 1, path + c)
            else:
                dfs(start + 1, path + S[start])
        
        dfs(0, '')
        return result
