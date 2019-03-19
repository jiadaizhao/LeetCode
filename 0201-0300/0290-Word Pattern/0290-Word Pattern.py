class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        table = {}
        mapped = set()
        words = str.split()
        if len(words) != len(pattern):
            return False
        for i, word in enumerate(words):            
            if word in table:
                if table[word] != pattern[i]:
                    return False
            else:
                if pattern[i] in mapped:
                    return False
                table[word] = pattern[i]
                mapped.add(pattern[i])
        return True
