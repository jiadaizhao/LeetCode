class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        result = []
        for word in words:
            table = {}
            mapped = set()
            match = True
            for i in range(len(pattern)):
                if pattern[i] not in table:
                    if word[i] in mapped:
                        match = False
                        break
                    table[pattern[i]] = word[i]
                    mapped.add(word[i])
                elif table[pattern[i]] != word[i]:
                    match = False
                    break
            if match:
                result.append(word)
        return result
