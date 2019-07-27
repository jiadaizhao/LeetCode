import collections
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        table = collections.Counter()
        total = 0
        for a, b in dominoes:
            if a > b:
                a, b = b, a
            total += table[(a, b)]
            table[(a, b)] += 1
        return total
