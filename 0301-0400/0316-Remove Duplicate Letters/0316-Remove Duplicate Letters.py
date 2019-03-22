import collections
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        table = collections.Counter(s)
        visited = set()
        result = []
        for c in s:
            table[c] -= 1
            if c in visited:
                continue
                
            while result and c < result[-1] and table[result[-1]] > 0:
                visited.remove(result[-1])
                result.pop()
                
            result.append(c)
            visited.add(c)
            
        return ''.join(result)
