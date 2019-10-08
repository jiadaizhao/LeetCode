import collections
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        table = collections.Counter(text)
        table['l'] //= 2
        table['o'] //= 2
        return min(table[key] for key in "balon")
