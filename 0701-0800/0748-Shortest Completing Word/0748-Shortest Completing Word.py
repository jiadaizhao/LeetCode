import collections
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        lp = collections.Counter(c.lower() for c in licensePlate if c.isalpha())
        minIndex = -1
        for i, word in enumerate(words):
            table = collections.Counter(word)
            if not (lp - collections.Counter(word)) and (minIndex == -1 or len(word) < len(words[minIndex])):
                minIndex = i
        return words[minIndex]

class Solution2:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        lp = collections.Counter(c.lower() for c in licensePlate if c.isalpha())
        return min([word for word in words if not (lp - collections.Counter(word))], key=len)
