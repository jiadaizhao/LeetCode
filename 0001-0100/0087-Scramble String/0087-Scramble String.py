import collections
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
        if collections.Counter(s1) != collections.Counter(s2):
            return False
        return any((self.isScramble(s1[:k], s2[:k]) and self.isScramble(s1[k:], s2[k:]))
                  or (self.isScramble(s1[:k], s2[-k:]) and self.isScramble(s1[k:], s2[:-k]))
                  for k in range(1, len(s1)))
