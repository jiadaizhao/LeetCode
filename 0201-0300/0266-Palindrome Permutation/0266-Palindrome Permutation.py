import collections
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        return sum(v&1 for v in collections.Counter(s).values()) <= 1
