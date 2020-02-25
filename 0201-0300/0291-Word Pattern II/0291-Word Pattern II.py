class Solution:
    def wordPatternMatch(self, pattern: str, str: str) -> bool:
        table = {}
        mapped = set()
        def dfs(pstart, sstart):
            if pstart == len(pattern):
                return sstart == len(str)
            for i in range(sstart, len(str)):
                if len(str) - i < len(pattern) - pstart:
                    break
                temp = str[sstart : i + 1]
                if temp in table:
                    if table[temp] != pattern[pstart]:
                        continue
                    elif dfs(pstart + 1, i + 1):
                        return True
                elif pattern[pstart] not in mapped:
                    table[temp] = pattern[pstart]
                    mapped.add(pattern[pstart])
                    if dfs(pstart + 1, i + 1):
                        return True
                    del table[temp]
                    mapped.remove(pattern[pstart])
            
            return False
        return dfs(0, 0)
