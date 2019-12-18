import collections
import itertools
class Solution:
    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        parent = {}
        table = collections.defaultdict(set)
        def findParent(x):
            parent.setdefault(x, x)
            table.setdefault(x, set([x]))
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        for a, b in synonyms:
            pa = findParent(a)
            pb = findParent(b)
            parent[pb] = pa
            table[pa] |= table[pb]
        words = text.split()
        result = []
        for word in text.split():
            if word not in parent:
                result.append([word])
            else:
                result.append(list(table[findParent(word)]))
                
        return sorted(' '.join(words) for words in itertools.product(*result))
