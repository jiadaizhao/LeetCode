class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def match(query, pattern):
            j = 0
            for c in query:
                if j < len(pattern) and c == pattern[j]:
                    j += 1
                elif not c.islower():
                    return False
            return j == len(pattern)
        
        return [match(query, pattern) for query in queries]
