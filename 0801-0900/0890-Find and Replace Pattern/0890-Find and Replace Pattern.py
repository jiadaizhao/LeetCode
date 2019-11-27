class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        result = []
        for word in words:
            table = {}
            mapped = set()
            for p, w in zip(pattern, word):
                if p not in table:
                    if w in mapped:
                        break
                    table[p] = w
                    mapped.add(w)
                elif table[p] != w:
                    break
            else:
                result.append(word)
                
        return result
