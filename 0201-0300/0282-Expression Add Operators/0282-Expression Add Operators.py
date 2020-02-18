class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        if not num:
            return []
        result = []
        def dfs(start, path, curr, prev):
            if start == len(num):
                if curr == target:
                    result.append(path)
                return
            
            for i in range(start, len(num)):
                s = num[start: i + 1]
                n = int(s)
                if str(n) != s:
                    break
                    
                if start == 0:
                    dfs(i + 1, s, n, n)
                else:
                    dfs(i + 1, path + '+' + s, curr + n, n)
                    dfs(i + 1, path + '-' + s, curr - n, -n)
                    dfs(i + 1, path + '*' + s, curr - prev + prev*n, prev*n)
        
        dfs(0, '', 0, 0)
        return result
