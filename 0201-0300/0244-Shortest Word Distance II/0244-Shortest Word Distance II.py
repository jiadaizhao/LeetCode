import collections
import math
class WordDistance:

    def __init__(self, words: List[str]):
        self.table = collections.defaultdict(list)
        for i, word in enumerate(words):
            self.table[word].append(i)

            
    def shortest(self, word1: str, word2: str) -> int:
        minDist = math.inf
        index1, index2 = self.table[word1], self.table[word2]
        p1 = p2 = 0
        while p1 < len(index1) and p2 < len(index2):
            minDist = min(minDist, abs(index1[p1] - index2[p2]))
            if index1[p1] < index2[p2]:
                p1 += 1
            else:
                p2 += 1

        return minDist


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
