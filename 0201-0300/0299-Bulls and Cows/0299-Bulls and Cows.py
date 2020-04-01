import collections
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        table = collections.Counter()
        bull = cow = 0
        for s, g in zip(secret, guess):
            if s == g:
                bull += 1
            else:
                if table[s] < 0:
                    cow += 1
                table[s] += 1
                if table[g] > 0:
                    cow += 1
                table[g] -= 1
        return str(bull) + 'A' + str(cow) + 'B'
