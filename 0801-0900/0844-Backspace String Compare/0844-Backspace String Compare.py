import itertools
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def getNext(s):
            b = 0
            for c in reversed(s):
                if c == '#':
                    b += 1
                elif b > 0:
                    b -= 1
                else:
                    yield c
        
        return all(x == y for x, y in itertools.zip_longest(getNext(S), getNext(T)))
