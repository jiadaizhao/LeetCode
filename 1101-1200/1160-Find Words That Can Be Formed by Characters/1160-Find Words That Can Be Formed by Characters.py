import collections
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        table = collections.Counter(chars)
        return sum(map(lambda word: 0 if collections.Counter(word) - table else len(word), words))
