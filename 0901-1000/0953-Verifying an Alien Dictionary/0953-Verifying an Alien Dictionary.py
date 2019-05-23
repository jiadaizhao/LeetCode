import itertools
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        table = {c: i for i, c in enumerate(order)}
        table[None] = -1
        for i in range(len(words) - 1):
            for a, b in itertools.zip_longest(words[i], words[i + 1]):
                if table[a] < table[b]:
                    break
                if table[a] > table[b]:
                    return False
                
        return True
