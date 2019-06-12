import collections
class Solution:
    def smallestSubsequence(self, text: str) -> str:
        table = collections.Counter(text)
        visited = set()
        result = []
        for c in text:
            table[c] -= 1
            if c in visited:
                continue
                
            while result and c < result[-1] and table[result[-1]] > 0:
                visited.remove(result.pop())
                
            result.append(c)
            visited.add(c)
            
        return ''.join(result)
