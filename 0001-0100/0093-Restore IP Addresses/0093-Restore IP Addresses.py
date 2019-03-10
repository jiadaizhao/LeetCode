class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []
        path = []
        def dfs(start):
            if len(path) == 4:
                if start == len(s):
                    result.append('.'.join(path))
                return
            
            for i in range(start, min(start + 3, len(s))):
                temp = s[start: i+1]
                num = int(temp)
                if 0 <= num <= 255 and (len(temp) == 1 or temp[0] != '0'):
                    path.append(temp)
                    dfs(i+1)
                    path.pop()
        dfs(0)
        return result
