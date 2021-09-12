class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        def isVowel(c):
            return c in "aeiou"
        maxLen = curr = 0
        for i, c in enumerate(s):
            if i >= k and isVowel(s[i - k]):
                curr -= 1
            if isVowel(c):
                curr += 1
            maxLen = max(maxLen, curr)
        return maxLen
