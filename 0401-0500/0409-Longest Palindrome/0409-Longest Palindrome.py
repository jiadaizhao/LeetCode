import collections
class Solution:
    def longestPalindrome(self, s: str) -> int:
        odds = sum(v&1 for v in collections.Counter(s).values())
        return len(s) - odds + bool(odds)
