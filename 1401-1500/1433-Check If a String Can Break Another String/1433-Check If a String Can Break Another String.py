import collections
class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        s1, s2 = sorted(s1), sorted(s2)
        break1 = break2 = True
        for i in range(len(s1)):
            if s1[i] < s2[i]:
                break1 = False
            if s2[i] < s1[i]:
                break2 = False
        return break1 or break2


class Solution2:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        def check(d1, d2):
            s = 0
            for i in range(26):
                c = chr(ord('a') + i)
                s += d1[c] - d2[c]
                if s < 0:
                    return False
            return True
        d1 = collections.Counter(s1)
        d2 = collections.Counter(s2)
        return  check(d1, d2) or check(d2, d1)
