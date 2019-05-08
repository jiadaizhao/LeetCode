import collections
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        table = collections.Counter((A + ' ' + B).split())
        return [word for word in table if table[word] == 1]
